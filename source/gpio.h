#ifndef GUARD_GPIO_H
#define GUARD_GPIO_H

#include <string>

class GPIO {
public:
	GPIO();
	GPIO(const std::string &num);
	int export_gpio();
	int unexport_gpio();
	int set_direction_out();
	int set_direction_in();
	int set_state_high();
	int set_state_low();
	int check_state(bool &value);
private:
	std::string  _gpionum;
	bool _is_input;
	bool _is_exported;
};

#endif

