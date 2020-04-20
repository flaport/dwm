# dwm - dynamic window manager
`dwm` is an extremely fast, small, and dynamic window manager for X.

## Patches
Each branch in this repository represents a single, often modified,
patch to vanilla dwm. Below you find all the applied patches in the
order they were merged into the master branch of this repository.

#### systray+alpha

* download [my combined patch](https://github.com/flaport/dwm/compare/upstream..systray+alpha.diff) ‧ [my alpha patch](https://github.com/flaport/dwm/compare/upstream..alpha.diff) ‧ [my systray patch](https://github.com/flaport/dwm/compare/upstream..systray.diff)
* see [combined branch](https://github.com/flaport/dwm/tree/systray+alpha) ‧ [alpha branch](https://github.com/flaport/dwm/tree/alpha) ‧ [systray branch](https://github.com/flaport/dwm/tree/systray)

Combining the `alpha` patch with the `systray` patch is not easy.
Hence, I first combined them in a separate branch, `systray+alpha`,
before merging them into master. I highly recommend using the combined
patch if you want both `alpha` and `systray` at the same time.

#### autostart

* download [my modified patch](https://github.com/flaport/dwm/compare/upstream..autostart.diff)
* see [branch](https://github.com/flaport/dwm/tree/autostart)
* see example [dwm_autostart](dwm_autostart) script.

The vanilla autostart patch from the suckless website is already very
minimal. In this modified patch, I removed the blocking call and
assumed the script `dwm_autostart` is added to the path. An example
[`dwm_autostart`](dwm_autostart) script can be found in this repository.

#### interactivestatusbar

* download [my custom patch](https://github.com/flaport/dwm/compare/upstream..interactivestatusbar.diff)
* see [branch](https://github.com/flaport/dwm/tree/interactivestatusbar)
* see example [dwm_status](dwm_status) script.

This is a completely custom patch I use to make the `dwm` status bar
interactive. The statusbar is still set with `xsetroot`, however a
unique character is used as delimiter between each widget. By using
this delimiter, `dwm` can figure out which widget was clicked and
calls in turn `dwm_status` (which should be placed in your path) with two
arguments: the widget index and the mouse button. The `dwm_status`
script can then use that info to start a specific action. An example
[`dwm_status`](dwm_status) script can be found in this repository.

#### hiddentag

* download [my custom patch](https://github.com/flaport/dwm/compare/upstream..hiddentag.diff)
* see [branch](https://github.com/flaport/dwm/tree/hiddentag)

This small custom patch adds a hidden (invisible) tag to the tagset.


#### mastermon

* download [my custom patch](https://github.com/flaport/dwm/compare/upstream..mastermon.diff)
* see [branch](https://github.com/flaport/dwm/tree/mastermon)

The mastermon patch introduces a "master" monitor. The master monitor
is the only monitor with tags. All other monitors will have no tags.
The tags from the master can be accessed (enabled/disabled/send to)
with the normal keybindings from any monitor. This makes the tag
system a lot less confusing in a multi monitor setup.

Why is this useful? In most multi-monitor setups you'll usually have a
preferred monitor to work on anyway. Other monitors will be less
important and will mostly be used to station content in view. If this
resembles your workflow, this patch is for you!

Some new kind of keybindings were added: `mod+[z|x|c|v]` to move focus
to monitor 1,2,3 or 4 and  `mod+shift+[z|x|c|v]` to move the focused
window to monitor 1,2,3 or 4. Moreover, `mod+ctrl+m` can be used to "promote"
the current monitor to the master monitor and `mod+ctrl+tab` to
quickly swap the content between two adjacent monitors.

#### tilegap

* download [my modified patch](https://github.com/flaport/dwm/compare/upstream..tilegap.diff)
* see [branch](https://github.com/flaport/dwm/tree/tilegap)

Gaps between windows. Who doesn't want them? I removed the borders
from non-active windows as well.

#### restartsig

* download [patch](https://github.com/flaport/dwm/compare/upstream..restartsig.diff)
* see [branch](https://github.com/flaport/dwm/tree/restartsig)

Restart `dwm` with `mod+ctrl+shift+q`

#### libxft-bgra

* download [my custom patch](https://github.com/flaport/dwm/compare/upstream..libxft-bgra.diff)
* see [branch](https://github.com/flaport/dwm/tree/libxft-bgra)

Enables color emojis when
[`libxft-bgra`](https://gitlab.freedesktop.org/xorg/lib/libxft/-/merge_requests/1)
is installed on the system (currently only checks this by doing a
Pacman query). If `libxft-bgra` is not installed, color emojis will be
ignored.

#### xrdb

* download [my modified patch](https://github.com/flaport/dwm/compare/upstream..xrdb.diff)
* see [branch](https://github.com/flaport/dwm/tree/xrdb)

Read in colors from Xresources and apply them to dwm.

#### center

* download [patch](https://github.com/flaport/dwm/compare/upstream..center.diff)
* see [branch](https://github.com/flaport/dwm/tree/center)

Place floating windows in the center of the screen.

#### fakefullscreen

* download [patch](https://github.com/flaport/dwm/compare/upstream..fakefullscreen.diff)
* see [branch](https://github.com/flaport/dwm/tree/fakefullscreen)

Only allow clients to fullscreen into space currently given to them.

#### fullscreen

* download [patch](https://github.com/flaport/dwm/compare/upstream..fullscreen.diff)
* see [branch](https://github.com/flaport/dwm/tree/fullscreen)

Due to `fakefullscreen`, which limits the fullscreen of an application
to its window size, we need a way to force fullscreen when we want it:
`mod+ctrl+f`.

## Older versions
This repository also contains some older versions of my dwm build as
seperate branches of this repository:

#### dwm v2

* download as [patch](https://github.com/flaport/dwm/compare/upstream..v2.diff)
* see [branch](https://github.com/flaport/dwm/tree/v2)

the current version (should be more or less up to date with master)


#### dwm v1

* download as [patch](https://github.com/flaport/dwm/compare/upstream..v1.diff)
* see [branch](https://github.com/flaport/dwm/tree/v1)

The previous version: a build with similar features as v2 but with
more bugs and less clean separation of the applied patches.

#### dwm v0

* download as [patch](https://github.com/flaport/dwm/compare/upstream..v0.diff)
* see [branch](https://github.com/flaport/dwm/tree/v0)

My first attempt at customizing `dwm`. Only here to archive. I do not
recommend building this one.

#### upstream

This branch attempts to be up to date with upstream dwm:
[git.suckless.org/dwm](http://git.suckless.org/dwm).

## Requirements
In order to build `dwm` you need the Xlib header files.

## Installation
Edit config.mk to match your local setup (`dwm` is installed into
the `/usr/local` namespace by default).

Afterwards enter the following command to build and install `dwm` (if
necessary as root):

```
    make clean install
```


## Running dwm
Add the following line to your `.xinitrc` to start `dwm` using `startx`:

```
    exec dwm
```

In order to connect `dwm` to a specific display, make sure that
the `DISPLAY` environment variable is set correctly, e.g.:

```
    DISPLAY=foo.bar:1 exec dwm
```

(This will start `dwm` on display `:1` of the host `foo.bar`.)

In order to display status info in the bar, you can do something
like this in your `.xinitrc`:

```
    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm
```


## Configuration
The configuration of `dwm` is done by creating a custom `config.h`
and (re)compiling the source code.

## Credits
This `dwm` fork is based on the suckless upstream: [https://dwm.suckless.org/](https://dwm.suckless.org/)
