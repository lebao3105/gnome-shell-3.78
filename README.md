## [GNOME Shell][project-wiki] 3.78
This is my customized GNOME 3.38 with a lot of customization!

## Features
* Customized application grid + dash
* Rounded on-screen keyboard
* Transparent app folder (on application grid)
* Hidden panel items arrow (Made on JS code, to re-enable revert the code change or use a GNOME extension)

Most changes are implemented in [data/theme/gnome-shell-sass/widgets](data/theme/gnome-shell-sass/widgets/).

## Get and install
**Critical**: This project CAN'T be built on GNOME 4x compatible OSes due to dependency conflicts. Tested on Debian 11 with GNOME 3.38.5 (higher a little bit than this project).

1.Clone this repository using ```git``` (you can choose another color [here](https://github.com/lebao3105/gnome-shell-3.78-pink), but it's now outdated) to your computer.<br>

2.Install build tools & dependencies:

  - Ubuntu, Debian, Linux Mint... (apt-based distributions)
  ```bash
   $ sudo apt build-dep gnome-shell && sudo apt install meson ninja-build
  ```

  - Fedora, RedHat... (rpm-based distros) <br>
  ```bash
   $ sudo dnf build-dep gnome-shell && sudo dnf install meson ninja-build
  ```
  > Tip: save packages the package manager install to remove them later, in case needed.

3.Build and install:

```bash
$ meson build --prefix=/usr
$ sudo ninja -C build install
```
4. Log out then log in back to see changes. You may need to reboot.

## Try GNOME 3.78's theme without installing

> Note: On GNOME 40+ environment you will get a bad dash if you use this project.

Try to use SCSS program to compile gnome-shell.scss from ```data/theme```. Then install it as a shell theme.

## My GNOME is broken!

There are ways to fix: enter a TTY session or to another DE then open Terminal first:
1. Reinstall the shell using your system package manager (the easiest way)
2. Build vanila GNOME Shell:
  * Get GNOME Shell source code in https://download.gnome.org/sources/gnome-shell/ (requires wget/curl) or use system's default package manager.
  * Extract your downloaded package.
  * Build GNOME Shell again like when you build this project.

If somehow you can't go to TTY* session, boot a live usb then chroot your local OS and do the fix.

If the problem still there, there may be problem(s) on your system, maybe broken packages etc.

## More things to do!
* Go to this [js/ui/panel.js line 436](https://github.com/lebao3105/gnome-shell-3.78/blob/main/js/ui/panel.js#L436) and change "Activities" text to "Overview" if you'd like to (keep "")
* Still js/ui/panel.js, but go to line 233-234, uncomment these lines if you want to have top panel arrows back.

Re-compile + install GNOME to apply the changes.

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
