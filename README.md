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
    done &amp;
    exec dwm
```

## Patches
The following patches were applied:
* [dwm-mastermonitor-6.2](https://github.com/flaport/dwm/tree/dwm-mastermonitor-6.2)
* [dwm-autostart-20161205-bb3bd6f](https://dwm.suckless.org/patches/autostart/)
* [dwm-cyclelayouts-20180524-6.2](https://dwm.suckless.org/patches/cyclelayouts/)
* [dwm-tilegap-6.2](https://dwm.suckless.org/patches/tilegap/)
* [dwm-fibonacci-5.8.2](https://dwm.suckless.org/patches/fibonacci/) [[patched for tilegap](https://github.com/flaport/dwm/blob/v0.1/fibonacci.c)]
* [dwm-systray-20190208-cb3f58a](https://dwm.suckless.org/patches/systray/)


## Configuration
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
