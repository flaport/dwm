# dwm - dynamic window manager

`dwm` is an extremely fast, small, and dynamic window manager for X.


## Requirements
In order to build `dwm` you need the `Xlib` header files.


## Installation
Edit `config.def.mk` to match your local setup and configure `config.def.h` to your liking. Afterwards enter the following command to build and install dwm:

```
    sudo make clean install
```

The `dwm` executable will be installed in `/usr/local/bin/`


## Running dwm
Add the following line to your `.xinitrc` to start dwm using `startx`:
```
    exec dwm
```

## Status bar and autostart
For the creation of a status bar, `dwm` expects two scripts to be available in the system path: `dwm_autostart` and `dwm_status`. 
`dwm_status` handles how the status bar looks using `xsetroot`; `dwm_autostart` handles how often the status bar gets updated and which other programs get started after starting `dwm`. A minimal example for both might look as follows:

#### `dwm_status:`
```
    xsetroot -name "flaport`s dwm fork"
```

#### `dwm_autostart`:
```
    # start other programs after dwm has started:
    sxhkd & # keyboard shortcut daemon started after dwm, so that dwm keyboard shortcut take precedence.
    
    # update status bar every 10 seconds
    # note that the status bar can also be updated manually by calling `dwm_status`.
    while true; do
        dwm_status
        sleep 10
    done &
```

A more complete example is included in this repository: [dwm_status](dwm_status), [dwm_autostart](dwm_autostart). Note that
this `dwm` fork also communicates mouse click events as arguments to `dwm_status`. Have a look at the included `dwm_status` script to see how this works.


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
* [dwm-restartsig-20180523-6.2](https://dwm.suckless.org/patches/restartsig/)

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
