## GNOME Shell
GNOME Shell provides core user interface functions for the GNOME 3 desktop,
like switching to windows and launching applications. GNOME Shell takes
advantage of the capabilities of modern graphics hardware and introduces
innovative user interface concepts to provide a visually attractive and
easy to use experience.

For more information about GNOME Shell, including instructions on how
to build GNOME Shell from source and how to get involved with the project,
see the [project wiki][project-wiki].

Bugs should be reported to the GNOME [bug tracking system][bug-tracker].

## Get and install
1.Clone this source (you can select another [color]) to your computer.<br>
2.Open Terminal and type:<br>
  - Ubuntu, Debian, Linux Mint... (apt-based distributions)
  ```
   $sudo apt build-dep gnome-shell && sudo apt install meson ninja-build
   ```
  - Fedora, RedHat... (rpm-based distros) <br>
   ```
   $sudo dnf build-dep gnome-shell && sudo apt install meson ninja-build
   ```
 You may need to install *mutter* manually.*Warning: Build GNOME 3.78 can take your system on your own risk!*<br>
3.Build and install:
```
   meson build --prefix=/usr
   ninja -C build
   ninja -C build install
```
4.Log out then log in back to see changes. 

## My GNOME is broken! What I need to do now?
If your GNOME Shell is broken (see an error like "Your system can't recover"), do the following:
* Download your preferred GNOME version here: https://download.gnome.org/sources/gnome-shell/
* Press Ctrl + Shift (or Alt?) + F3 to enter TTY shell.
* Log in your account (if required) using your account name (usually is the folder name in /home) and your password.
* Use ```tar``` to extract the dowloaded source code, then build again like when you build gnome 3.78.
* Reboot again. <br>
And more, if you have other Desktop Environment like KDE, Cinnamon, Mate... and have other Display Manager (lightdm), it is easy to ignore the broken DE, log in to use other DE, and fix the error. You may can start the DE (not GNOME) by ```startx``` from the Command-Shell.

## Contributing to GNOME

To contribute, open merge requests at https://gitlab.gnome.org/GNOME/gnome-shell.

Commit messages should follow the [GNOME commit message
guidelines](https://wiki.gnome.org/Git/CommitMessages). We require an URL
to either an issue or a merge request in each commit.

## License
GNOME Shell is distributed under the terms of the GNU General Public License,
version 2 or later. See the [COPYING][license] file for details.

[project-wiki]: https://wiki.gnome.org/Projects/GnomeShell
[bug-tracker]: https://gitlab.gnome.org/GNOME/gnome-shell/issues
[license]: COPYING
[color]:https://github.com/lebao3105/gnome-shell-3.78-pink
