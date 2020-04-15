# dwm - dynamic window manager
`dwm` is an extremely fast, small, and dynamic window manager for X.

## Patches
Each branch in this repository represents a single, often modified,
patch to vanilla dwm. Below you find all the applied patches in the
order they were merged into the master branch of this repository.

#### systray+alpha

* download [my combined patch](https://github.com/flaport/dwm/compare/upstream..systray+alpha.diff) ‧ [my alpha patch](https://github.com/flaport/dwm/compare/upstream..alpha.diff) ‧ [my systray patch](https://github.com/flaport/dwm/compare/upstream..systray.diff)
* see [my combined branch](https://github.com/flaport/dwm/tree/systray+alpha) ‧ [my alpha branch](https://github.com/flaport/dwm/tree/alpha) ‧ [my systray branch](https://github.com/flaport/dwm/tree/systray)

Combining the `alpha` patch with the `systray` patch is not easy.
Hence, I first combined them in a separate branch, `systray+alpha`,
before merging them into master. I highly recommend using the combined
patch if you want both `alpha` and `systray` at the same time.


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
