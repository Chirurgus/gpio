#ifndef GUARD_GPIO_AUX_H
#define GUARD_GPIO_AUX_H

#include <string>

int parse_args(int argc, char** argv, const std::string &gpio_num, bool as_input);

#endif
