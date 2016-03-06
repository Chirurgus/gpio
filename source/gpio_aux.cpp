#include "gpio_aux.h"

#include <string>
#include <iostream>

using namespace std;

int write_help_message() {
	if (cout <<
		"gpio by Alexander\n"
		"gpio allows you to control Pi's gpio ports.\n"
		"Usage: gpio [ARGUMENTS] [GPIO_NUM]\n"
		"Arguments:\n"
		"\t-i, --input      Set direction to input\n"
		"'t-o, --output     Set direction to out\n"
		"\t-c, --check      Get curent GPIO value\n"
		"\t-s, --set        Set GPIO to a value\n"
		"\t-l, --status     List all active GPIO ports\n"
		"\t-u, --unexport   Disactivate a GPIO port\n"
		"\t-e, --export     Activate a GPIO port\n"
		"\t-h, --help       Get help\n")
		return 0;//Everything is a O.K.
	else
		return 1;//Maybe write something to std::err???
}

int write_error_message() {
	if (cout <<
		"Wrong syntax!\n"
		"For help enter -h or --help.\n")
		return 0;
	else
		return 1;//Maybe write something to std::err???
}

int write_error_message(const std::string &err_msg) {
	if (cout << err_msg)
		return 0;
	else
		return 1;
}

int write_status_message(const std::string & str_msg)
{
	if (cout << str_msg)
		return 0;
	else
		return 1;
}
