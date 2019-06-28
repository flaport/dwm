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

## Autostart and status bar
Make sure the two shell scripts `dwm_autostart` and `dwm_status` are in your path to
have a fully functional status bar


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
* [dwm-fsignal-6.1](https://dwm.suckless.org/patches/fsignal/)
* [dwm-6.0-winview](https://dwm.suckless.org/patches/winview/)
* [dwm-deck-6.0](https://dwm.suckless.org/patches/deck/)
* [dwm-alpha-20180613-b69c870](https://dwm.suckless.org/patches/alpha/)

## Master Monitor patch
The [mastermonitor patch](https://github.com/flaport/dwm/tree/dwm-mastermonitor-6.2) is a
custom patch incorporated in commit `55a46c0` patching the `dwm-6.2` 
release at `cb3f58a`. It can also be found in the `dwm-mastermonitor-6.2` branch of this
repository.

The patch introduces a "master" monitor.

The master monitor is the only monitor with tags. All other monitors will have no tags.
The tags from the master can be accessed (enabled/disabled/send to) with the normal
keybindings from any monitor. This makes the tag system a lot less confusing in a multi
monitor setup.

Why is this useful? In most multi-monitor setups you'll usually have a preferred monitor
to work on anyway. Other monitors will be less important and will mostly
be used to station content in view. If this resembles your workflow,
this patch is for you!

Two new kind of keybindings were added: [Control]+[1..n] to move focus to monitor n and
[Control]+[Shift]+[1..n] to move the focused window to monitor n.

The behavior of the default keybindings to view/toggle/tag tags was
changed in such a way that they always have effect on the tags of the
master monitor.

## Configuration
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
