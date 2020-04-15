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
Add the following line to your .xinitrc to start `dwm` using `startx`:

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
