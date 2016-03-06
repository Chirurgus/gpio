#ifndef GUARD_GPIO_AUX_H
#define GUARD_GPIO_AUX_H

#include <string>

int write_help_message();
int write_error_message();/* I'm lazy so it's a generic error message for all errors*/
int write_error_message(const std::string &err_msg);
int write_status_message(const std::string &str_msg);

#endif
