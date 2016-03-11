#include "gpio.h"
#include "gpio_aux.h"
#include "arguments.h"

#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {

	Arguments args(argc, argv);
	args.Check();

	if (args.err_bit == true) {
		write_error_message();
		return 1;
	}

	if (args.h_checked) {    /* User asked for help */
		write_help_message();/* Give him help and ignore the rest */
		return 0;
	}

	GPIO gpio0(args.gpio_num);

	if (args.l_checked) {
		write_status_message("For the time bing this is  useles. soooo...\n");
		return 0;
	}

	if (args.u_checked) {
		if (gpio0.unexport_gpio()) {
			write_error_message("Can't un-export gpio port #" + args.gpio_num + ".\n");
			return 1;
		}
		else
			return 0;//Gpio un-Exported, nothing more to do.
	}

	if (args.e_checked) {
		if (gpio0.export_gpio()) {
			write_error_message("Can't export gpio port #" + args.gpio_num + ".\n");
			return 1;
		}//GPIO exported, but there might still be other stuff to do.
	}

	if (args.i_checked) {/* Shouldn't be checked at the same time as o_checked */
		if (gpio0.set_direction_in()) {
			write_error_message("Can't set direction for gpio port #" + args.gpio_num + ".\n");
			return 1;
		}
	}

	if (args.o_checked) {/* Shouldn't be checked at the same time as i_checked*/
		if (gpio0.set_direction_out()) {
			write_error_message("Can't set direction for gpio port #" + args.gpio_num + ".\n");
			return 1;
		}
	}

	if (args.s_checked) {
		if (args.set_to_high) {
			if (gpio0.set_state_high()) {
				write_error_message("Can't set state to high for gpio port #" + args.gpio_num + ".\n");
				return 1;
			}
		}
		else {/* If set_to_high = false */
			if (gpio0.set_state_low()) {
				write_error_message("Can't set state to low for gpio port #" + args.gpio_num + ".\n");
				return 1;
			}
		}
	}

	if (args.c_checked) {
		bool is_high; /* Lol */
		if (gpio0.check_state(is_high)) {
			write_error_message("Can't check state of gpio port #" + args.gpio_num + ".\n");
			return 1;
		}
		else {
			write_status_message("gpio #" + args.gpio_num + " is " + (is_high ? "high" : "low") + '\n');
		}
	}
	/* We have come a long way my friend */
	return 0;
	/* Might as well exit with 0(SUCESS) */
}