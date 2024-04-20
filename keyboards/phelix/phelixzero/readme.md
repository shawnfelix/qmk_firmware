
# phelix zero low profile keyboard
    ┌──────────────────────────────────┐        ┌──────────────────────────────────────┐
    │ phelix               ┌────────┐  │        │                                      │
    │             o  o  o  │  LCD   │  │        │                                (  )  │
    │                      └────────┘  │        │  zero                                │
    ├────┬────┬────┬────┬────┬────┬────┤        ├────┬────┬────┬────┬────┬────┬────────┤
    │    │    │    │    │    │    │    │        │    │    │    │    │    │    │        │
    ├────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┘     ┌──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──────┤
    │      │    │    │    │    │    │        │    │    │    │    │    │    │    │      │
    ├──────┴┬───┴┬───┴┬───┴┬───┴┬───┴┐       └┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴──────┤
    │       │    │    │    │    │    │        │    │    │    │    │    │    │          │
    ├───────┴┬───┴┬───┴┬───┴┬───┴┬───┴┐       └┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬────┬────┤
    │        │    │    │    │    │    │        │    │    │    │    │    │    │    │    │
    ├─────┬──┴──┬─┴───┬┴────┼────┴────┤        ├────┴────┼────┼────┼────┼────┼────┼────┤
    │     │     │     │     │         │        │         │    │    │    │    │    │    │
    └─────┴─────┴─────┴─────┴─────────┘        └─────────┴────┴────┴────┴────┴────┴────┘


A split layout 60% low profile keyboard made and sold by phelix keyboards.\
Currently in development and v1 prototype manufacturing is in progress.

* Keyboard Maintainer: [Shawn Felix](https://github.com/shawnfelix)
* Hardware Supported: phelix-zero
* Hardware Availability: coming soon

## Features
* Built in 172x320 Color LCD Screen
* Low Profile Gateron Compatible
* Hotswap
* 1x Rotary Encoder
* Sandwich style keyboard with custom screw gaskets
* Aluminum Plate
* Opal Acrylic Base
* Programmable buttons

## LCD Screen 
The **phelix zero** has a full color 172x320 display embedded in the board.\
\
**There are endless options for customizing what is displayed on the screen**
* Clock and Timers
* Weather
* Customizable Widgets
* Wallpapers
* Words Per Minute Tracker
* Minigames and more...

## Flashing 
Make example for this keyboard (after setting up your build environment):

    make phelix/phelixzero:default

Flashing example for this keyboard:

    make phelix/phelixzero:default:flash

## Want to customize your phelix zero firmware further?

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
