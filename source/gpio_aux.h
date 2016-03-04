#ifndef GUARD_GPIO_AUX_H
#define GUARD_GPIO_AUX_H

#include <string>

int parse_args(int argc, char** argv, std::string &gpio_num, bool &as_input);
int get_direction(const char* dir, bool &is_input);


const char* help_string= "\t-i or --input\n\t-o or --output\n\t-h -l or --high --low\n\t-c or --check\n\t-s or --status\n\t-u or --unexport\n\t-e or --export\n";
/*
	gpio by Alexander
	Syntax:gpio [ARGUMENTS] [GPIO_NUM]
		-i or --input
		-o or --output   Set direction to out
		-c or --check    Get gpio value
		-s or --set
		-l or --status (Why -m? Cuz i'm the author)
		-u or --unexport (delete or disactivate)
		-e or --export 
		-h or --help
*/
#endif
