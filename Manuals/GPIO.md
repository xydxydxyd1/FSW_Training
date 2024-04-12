In this exercise, you will get to explore how the lowest layer of IntelliSat (GPIO) works

# The Goal
* Realize that every hardware configuration requires GPIO behind the scenes
* Learn how STM32 Programming involves programming low level hardware modules by setting and resetting bits in some register

# The Exercise

## Part 1: Blinky
One of the first projects in embedded systems is blinking an LED. This is often done as part of complex board bringup steps, but here we'll keep it simple. A lot of configurations have been done (the board starts up fine, and most gpio is configured). In `gpio_.h` file, you'll see:
- `_gpio_set()`: Used to change the state of some GPIO Pin. Check the usage details in the `gpio_.h` header file
- `GPIO_VALUE` : An enum for `value` arguement of `_gpio_set()`

Your task is to use the `_gpio_set()` function to toggle an LED every 1 second. Use the `delay_ms()` function from `globals.h`. In case you don't want to use `_gpio_set()`, you can also use `_gpio_low()` and `_gpio_high()` from `gpio_.h` header file.
In order to choose the GPIO pin for an LED, look under the *GPIO* tab of the [IntelliSat Hardware Configurations](https://docs.google.com/spreadsheets/d/1z3AKVA0EOj9eafCyiSpq6Oks2v7-z21BrvQfGa0dQ-E/edit?usp=sharing) google sheet. This is important because the GPIO pins for LEDs change across Orbital Platform revisions. **Pick any LED other than the Heatbeat LED, and look at the GPIO Port and Pin for it**. 
Here's some pseudocode to guide you:
```
branch_main() {
    while (1) {
        // set pin
        // delay
        // reset pin
        // delay
    }
}
```
When you flash and , you will notice that the Heartbeat LED of the Orbital Platform won't blink. This is intentional. But the LED you chose should blink.

## Part 2: GPIO Configuration
For fun, try doing the above procedure for the Heartbeat LED. (Use the [IntelliSat Hardware Configurations](https://docs.google.com/spreadsheets/d/1z3AKVA0EOj9eafCyiSpq6Oks2v7-z21BrvQfGa0dQ-E/edit?usp=sharing) google sheet again).
```
branch_main() {
    while (1) {
        // toggle logic but for gpio pin GPIOE-2  (Heartbeat LED)
    }
}
```
When you try it, it won't work. Why is that?

GPIO pins require configuring in order to function. Some of the guides and resources given to you as part of the [FSW Training document](https://docs.google.com/document/d/1e4uV5RjFFFbwAS2kfP6IOJJQl-huPxwL6-3UlMpI6uA/edit?usp=sharing) will mention what needs to be configured. But the Reference Manual is also useful here (specifically the GPIO section). When configuring registers, use the other functions in `_gpio.c` as reference, and also use the enums in `_gpio.h` to determine what the settings on each register needs to be

Your task is to complete the `_gpio_configure_mode()` function using the information above. Once you've done so, call this function at the very top of your branch_main() function:
```
branch_main() {
    _gpio_configure_mode(GPIOE, 2, ...)

    while (1) {
        // toggle logic but for gpio pin GPIOE-2  (Heartbeat LED)
    }
}
```
Note the `...` in the arguements. The [IntelliSat Hardware Configurations](https://docs.google.com/spreadsheets/d/1z3AKVA0EOj9eafCyiSpq6Oks2v7-z21BrvQfGa0dQ-E/edit?usp=sharing) google sheet mentions the mode, but you can keep the rest as default (look under `gpio_.h` for the macros/enums for those)
If your configuration function was written correctly, the Heartbeat LED will function now!