/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */

#include "config.h"

#include <gdk/gdkx.h>
#include <clutter/x11/clutter-x11.h>

#include "shell-embedded-window-private.h"

/* This type is a subclass of GtkWindow that ties the window to a
 * ShellGtkEmbed; the resizing logic is bound to the clutter logic.
 *
 * The typical usage we might expect is
 *
 *  - ShellEmbeddedWindow is created and filled with content
 *  - ShellEmbeddedWindow is shown with gtk_widget_show_all()
 *  - ShellGtkEmbed is created for the ShellEmbeddedWindow
 *  - actor is added to a stage
 *
 * The way it works is that the GtkWindow is mapped if and only if both:
 *
 * - gtk_widget_visible (window) [widget has been shown]
 * - Actor is mapped [actor and all parents visible, actor in stage]
 */

enum {
   PROP_0
};

typedef struct _ShellEmbeddedWindowPrivate ShellEmbeddedWindowPrivate;

struct _ShellEmbeddedWindowPrivate {
  ShellGtkEmbed *actor;

  GdkRectangle position;
};

G_DEFINE_TYPE_WITH_PRIVATE (ShellEmbeddedWindow,
                            shell_embedded_window,
                            GTK_TYPE_WINDOW);

/*
 * The normal gtk_window_show() starts all of the complicated asynchronous
 * window resizing code running; we don't want or need any of that.
 * Bypassing the normal code does mean that the extra geometry management
 * available on GtkWindow: gridding, maximum sizes, etc, is ignored; we
 * don't really want that anyways - we just want a way of embedding a
 * GtkWidget into a Clutter stage.
 */
static void
shell_embedded_window_show (GtkWidget *widget)
{
  ShellEmbeddedWindow *window = SHELL_EMBEDDED_WINDOW (widget);
  ShellEmbeddedWindowPrivate *priv;
  GtkWidgetClass *widget_class;

  priv = shell_embedded_window_get_instance_private (window);

  /* Skip GtkWindow, but run the default GtkWidget handling which
   * marks the widget visible */
  widget_class = g_type_class_peek (GTK_TYPE_WIDGET);
  widget_class->show (widget);

  if (priv->actor)
    {
      /* Size is 0x0 if the GtkWindow is not shown */
      clutter_actor_queue_relayout (CLUTTER_ACTOR (priv->actor));

      if (clutter_actor_is_realized (CLUTTER_ACTOR (priv->actor)))
        gtk_widget_map (widget);
    }
}

static void
shell_embedded_window_hide (GtkWidget *widget)
{
  ShellEmbeddedWindow *window = SHELL_EMBEDDED_WINDOW (widget);
  ShellEmbeddedWindowPrivate *priv;

  priv = shell_embedded_window_get_instance_private (window);

  if (priv->actor)
    clutter_actor_queue_relayout (CLUTTER_ACTOR (priv->actor));

  GTK_WIDGET_CLASS (shell_embedded_window_parent_class)->hide (widget);
}

static gboolean
shell_embedded_window_configure_event (GtkWidget         *widget,
                                       GdkEventConfigure *event)
{
  /* Normally a configure event coming back from X triggers the
   * resizing logic inside GtkWindow; we just ignore them
   * since we are handling the resizing logic separately.
   */
  return FALSE;
}

static void
shell_embedded_window_check_resize (GtkContainer *container)
{
  ShellEmbeddedWindow *window = SHELL_EMBEDDED_WINDOW (container);
  ShellEmbeddedWindowPrivate *priv;

  priv = shell_embedded_window_get_instance_private (window);

  /* Check resize is called when a resize is queued on something
   * inside the GtkWindow; we need to make sure that in response
   * to this gtk_widget_size_request() and then
   * gtk_widget_size_allocate() are called; we defer to the Clutter
   * logic and assume it will do the right thing.
   */
  if (priv->actor)
    clutter_actor_queue_relayout (CLUTTER_ACTOR (priv->actor));
}

static GObject *
shell_embedded_window_constructor (GType                  gtype,
                                   guint                  n_properties,
                                   GObjectConstructParam *properties)
{
  GObject *object;
  GObjectClass *parent_class;

  parent_class = G_OBJECT_CLASS (shell_embedded_window_parent_class);
  object = parent_class->constructor (gtype, n_properties, properties);

  /* Setting the resize mode to immediate means that calling queue_resize()
   * on a widget within the window will immediately call check_resize()
   * to be called, instead of having it queued to an idle. From our perspective,
   * this is ideal since we just are going to queue a resize to Clutter's
   * idle resize anyways.
   */
  g_object_set (object,
                "app-paintable", TRUE,
                "resize-mode", GTK_RESIZE_IMMEDIATE,
                "type", GTK_WINDOW_POPUP,
                NULL);

  return object;
}

static void
shell_embedded_window_class_init (ShellEmbeddedWindowClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
  GtkContainerClass *container_class = GTK_CONTAINER_CLASS (klass);

  object_class->constructor     = shell_embedded_window_constructor;

  widget_class->show            = shell_embedded_window_show;
  widget_class->hide            = shell_embedded_window_hide;
  widget_class->configure_event = shell_embedded_window_configure_event;

  container_class->check_resize    = shell_embedded_window_check_resize;
}

static void
shell_embedded_window_init (ShellEmbeddedWindow *window)
{
}

/*
 * Private routines called by ShellGtkEmbed
 */

void
_shell_embedded_window_set_actor (ShellEmbeddedWindow  *window,
                                  ShellGtkEmbed        *actor)

{
  ShellEmbeddedWindowPrivate *priv;

  g_return_if_fail (SHELL_IS_EMBEDDED_WINDOW (window));

  priv = shell_embedded_window_get_instance_private (window);
  priv->actor = actor;

  if (actor &&
      clutter_actor_is_mapped (CLUTTER_ACTOR (actor)) &&
      gtk_widget_get_visible (GTK_WIDGET (window)))
    gtk_widget_map (GTK_WIDGET (window));
}

void
_shell_embedded_window_allocate (ShellEmbeddedWindow *window,
                                 int                  x,
                                 int                  y,
                                 int                  width,
                                 int                  height)
{
  ShellEmbeddedWindowPrivate *priv;
  GtkAllocation allocation;

  g_return_if_fail (SHELL_IS_EMBEDDED_WINDOW (window));

  priv = shell_embedded_window_get_instance_private (window);

  if (priv->position.x == x &&
      priv->position.y == y &&
      priv->position.width == width &&
      priv->position.height == height)
    return;

  priv->position.x = x;
  priv->position.y = y;
  priv->position.width = width;
  priv->position.height = height;

  if (gtk_widget_get_realized (GTK_WIDGET (window)))
    gdk_window_move_resize (gtk_widget_get_window (GTK_WIDGET (window)),
                            x, y, width, height);

  allocation.x = 0;
  allocation.y = 0;
  allocation.width = width;
  allocation.height = height;

  gtk_widget_size_allocate (GTK_WIDGET (window), &allocation);
}

void
_shell_embedded_window_map (ShellEmbeddedWindow *window)
{
  g_return_if_fail (SHELL_IS_EMBEDDED_WINDOW (window));

  if (gtk_widget_get_visible (GTK_WIDGET (window)))
    gtk_widget_map (GTK_WIDGET (window));
}

void
_shell_embedded_window_unmap (ShellEmbeddedWindow *window)
{
  g_return_if_fail (SHELL_IS_EMBEDDED_WINDOW (window));

  gtk_widget_unmap (GTK_WIDGET (window));
}

/*
 * Public API
 */
GtkWidget *
shell_embedded_window_new (void)
{
  return g_object_new (SHELL_TYPE_EMBEDDED_WINDOW,
                       NULL);
}
