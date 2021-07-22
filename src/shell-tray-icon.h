/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */
#ifndef __SHELL_TRAY_ICON_H__
#define __SHELL_TRAY_ICON_H__

#include "shell-gtk-embed.h"

#define SHELL_TYPE_TRAY_ICON (shell_tray_icon_get_type ())
G_DECLARE_FINAL_TYPE (ShellTrayIcon, shell_tray_icon,
                      SHELL, TRAY_ICON, ShellGtkEmbed)

ClutterActor *shell_tray_icon_new      (ShellEmbeddedWindow *window);

void          shell_tray_icon_click    (ShellTrayIcon       *icon,
                                        ClutterEvent        *event);

#endif /* __SHELL_TRAY_ICON_H__ */
