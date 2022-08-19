## GNOME Shell 3.78
This is my customized GNOME Shell 3.38 with GNOME 40 look!

This will keep the old GNOME's applications grid, but also have a nicer look.

## Get and install
1.Clone this source (you can select another [color]) to your computer.<br>
2.Open Terminal and type:<br>
  - Ubuntu, Debian, Linux Mint... (apt-based distributions)
  ```
   $sudo apt build-dep gnome-shell && sudo apt install meson ninja-build
   ```
  - Fedora, RedHat... (rpm-based distros) <br>
   ```
   $sudo dnf build-dep gnome-shell && sudo dnf install meson ninja-build
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
* Get GNOME Shell source code in https://download.gnome.org/sources/gnome-shell/ or use system's default package manager.
* Press Ctrl + Shift + F3 to enter TTY session.
* Log in your account (if required) using your account name (usually is the folder name in /home) and your password.
* Build GNOME Shell again like when you build gnome 3.78.
* Reboot to see your desktop alive again:) <br>

## Reporting bugs
Because I'm using an old GNOME version, so if there are any shell bug happends, you should return to system's one.

But if there are any theming issue here, report it to me. I'm working on them.

## Screenshot(s)
![Screenshot from 2022-08-18 22-24-17](https://user-images.githubusercontent.com/77564176/185434779-867fc04d-a87f-4e71-a280-f3f8290e9c39.png)
![Screenshot from 2022-08-18 22-31-41](https://user-images.githubusercontent.com/77564176/185434861-66725a55-bf10-4a5f-b913-ed687c74576f.png)

## License
GNOME Shell is distributed under the terms of the GNU General Public License,
version 2 or later. See the [COPYING][license] file for details.

[project-wiki]: https://wiki.gnome.org/Projects/GnomeShell
[bug-tracker]: https://gitlab.gnome.org/GNOME/gnome-shell/issues
[license]: COPYING
