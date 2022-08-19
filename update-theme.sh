#!/bin/sh
#mkdir ~/.themes
#kdir ~/.themes/JK
#rm -rf build
#meson build
#ninja -C build data/theme/gnome-shell.css
cp build/data/theme/gnome-shell.css ~/.themes/JK/gnome-shell
echo "Done, please select JK shell theme from GNOME Tweaks."