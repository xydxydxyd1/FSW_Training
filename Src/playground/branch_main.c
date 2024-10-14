#include <globals.h>

#include <LED/led.h>
#include <Buttons/buttons.h>
#include <print_scan.h>

void main_loop() {
	// Button reaciton
	if (get_buttonStatus_1()) {
		printMsg("Button 1 is pressed");
	}
	if (get_buttonStatus_0()) {
		printMsg("Button 0 is pressed");
	}

	// Blink
	static int last_blink_time = -1000;
	static bool last_blink_state = false;
	int currtime = getSysTime();
	if (currtime - last_blink_time >= 1000) {
		last_blink_time = currtime;
		last_blink_state = !last_blink_state;
		led_a(last_blink_state);
	}
}

void branch_main() {
	// space for initializations

	while (1) {
		main_loop();
	}

	// infinite loop
	while (1) {

	}

	// NOTE
	// Always keep the system in the infinite while loop. Never break out of it
	// There is no place for the computer to go once you break out of this loop
}
