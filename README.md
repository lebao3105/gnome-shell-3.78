## GNOME Shell 3.78
This is my customized GNOME Shell 3.38 with a lot of customization!

## Features
* Customized application grid + dash
* Circular on-screen keyboard
* Transparent app folder (on application grid)
* Disabled panel items arrow (New)

Most changes are implemented from [data/theme/gnome-shell-sass/widgets](data/theme/gnome-shell-sass/widgets/).

## Get and install
**Critical**:Please note that this project CAN'T be built on OS that have GNOME 4x preinstalled. Tested on Debian 11 with GNOME 3.38.5 (higher than this project).

1.Clone this repository using ```git``` (you can select another [color](https://github.com/lebao3105/gnome-shell-3.78-pink)) to your computer.<br>

2.Install build tools & dependencies:<br>
  - Ubuntu, Debian, Linux Mint... (apt-based distributions)
  ```
   $sudo apt build-dep gnome-shell && sudo apt install meson ninja-build
  ```
  - Fedora, RedHat... (rpm-based distros) <br>
  ```
   $sudo dnf build-dep gnome-shell && sudo dnf install meson ninja-build
  ```
  > Tip: save packages the package manager install to remove it later, if you don't want to build GNOME Shell from source anymore.

3.Build and install:
```
   meson build --prefix=/usr
   ninja -C build
   ninja -C build install
```
4.Log out then log in back to see changes. 

## Try GNOME 3.78's theme without installing
1. ```meson build``` this project first, anyway.
2. Build: ```ninja -C build data/theme/gnome-shell.css```
3. Once done, copy build/data/theme/gnome-shell.css to ```~/.themes/<your own theme>/gnome-shell/```.
4. Make sure that GNOME Tweaks & User themes extension are installed.
5. Choose your created theme from Tweaks -> Apperance -> Shell theme.

## My GNOME is broken! What I need to do now?
If your GNOME Shell is broken (see an error like "Your system can't recover"), there are 2 ways to fix it:
1. Reinstall the shell using your system package manager (the easiest way)
2. Build vanila GNOME Shell:
  * Get GNOME Shell source code in https://download.gnome.org/sources/gnome-shell/ or use system's default package manager.
  * Press Ctrl + Shift + F3 to enter TTY session.
  * Log in your account (if required) using your account name (usually is the folder name in /home) and your password.
  * Build GNOME Shell again like when you build gnome 3.78.

After completed, restart your computer is the most recommended way:)

## Reporting bugs
Because I'm using an old GNOME version, so if there are any shell bug happends, you should return to system's one.

But if there are any theming issue here, report it to me. I'm working on them.

## Screenshots
![Screenshot from 2022-08-18 22-24-17](https://user-images.githubusercontent.com/77564176/185434779-867fc04d-a87f-4e71-a280-f3f8290e9c39.png)
![Screenshot from 2022-08-18 22-31-41](https://user-images.githubusercontent.com/77564176/185434861-66725a55-bf10-4a5f-b913-ed687c74576f.png)
![Screenshot from 2022-08-19 15-13-33](https://user-images.githubusercontent.com/77564176/185575162-9a1b08b5-2c64-4a2f-9ba2-b80734b3f7c2.png)

## License
GNOME Shell is distributed under the terms of the GNU General Public License,
version 2 or later. See the [COPYING][license] file for details.

[project-wiki]: https://wiki.gnome.org/Projects/GnomeShell
[bug-tracker]: https://gitlab.gnome.org/GNOME/gnome-shell/issues
[license]: COPYING
