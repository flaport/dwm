# dwm - dynamic window manager
dwm is an extremely fast, small, and dynamic window manager for X.


## Requirements
In order to build dwm you need the Xlib header files.


## Installation
Edit `config.def.mk` to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

```
    make clean install
```


## Running dwm
Add the following line to your .xinitrc to start dwm using startx:
```
    exec dwm
```

In order to display status info in the bar, you can do something
like this in your .xinitrc:

```
    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm
```

## Patches
The following patches were applied:
* [`https://dwm.suckless.org/patches/autostart/`](https://dwm.suckless.org/patches/autostart/)
* [`https://dwm.suckless.org/patches/combo/`](https://dwm.suckless.org/patches/combo/)
* [`https://dwm.suckless.org/patches/cyclelayouts/`](https://dwm.suckless.org/patches/cyclelayouts/)
* [`https://dwm.suckless.org/patches/tilegap/`](https://dwm.suckless.org/patches/tilegap/)
* [`https://dwm.suckless.org/patches/fibonacci/`](https://dwm.suckless.org/patches/fibonacci/) [manually patched for gaps]
* [`https://dwm.suckless.org/patches/alpha/`](https://dwm.suckless.org/patches/alpha/)
* [`https://dwm.suckless.org/patches/systray/`](https://dwm.suckless.org/patches/systray/)
* [`https://dwm.suckless.org/patches/deck/`](https://dwm.suckless.org/patches/deck/)
* [`https://dwm.suckless.org/patches/winview/`](https://dwm.suckless.org/patches/winview/)
* [`https://dwm.suckless.org/patches/fsignal/`](https://dwm.suckless.org/patches/fsignal/)


## Configuration
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
