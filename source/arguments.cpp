#include "arguments.h"
#include <cstdlib>

Arguments::Arguments(int argc, char** argv):err_bit(false), i_checked(false), o_checked(false) {
	/* All arguments are not set, unless specified otherwise */
	Set_all_to_false();

	/* If less then 2 arguments are provided, check if it is the --help option, if not set the err_bit = true */
	if (argc <= 2) {
		if (argc == 2 && Checking_for_h_checked(argv[1])) {
			h_checked = true;
		}
		else {
			err_bit = true;
		}
	}
	else {//Parsing arguments
		for (unsigned i = 1; i < argc - 1; i++) {//argc-1 because the last arguments is always the gpio_num
			if (*(argv[i]) == '-') {// Read arguments with '-' in front of them.
				argv[i]++;
				if (*(argv[i]) == '-') {//Read explicit long arguments.
					argv[i]++;
					Parsing_long_args(argv[i], i);
				}
				else {//read single letter arguments
					Parsing_short_args(argv[i], i);
				}
			}
			else {//If the first char of the string is not '-'
				err_bit = true;
			}
		}//End of Parse for loop
		/* Get gpio number. */
		int gpio_int = atoi(argv[argc - 1]);//atoi returns 0 if it didn't find a int, otherwise returns int
		if (gpio_int && gpio_int <= 27)//Checking if the int is in range(and that's it's an int)
			gpio_num = argv[argc - 1];
		else
			err_bit = true;
	}
}

void Arguments::Check()
{
	if (o_checked && i_checked)//Setting to output, and input at the same time
		err_bit = true;        //if and only if user is stupid
	if (i_checked && s_checked)
		err_bit = true;
	if (u_checked && (i_checked ||
					    o_checked ||
					    c_checked ||
					    s_checked ||
					    l_checked ||
					    e_checked))
		err_bit = true;
	if (l_checked && (i_checked ||
						o_checked ||
						c_checked ||
						s_checked ||
						u_checked ||
						e_checked))
		err_bit = true;
}

void Arguments::Set_all_to_false() {
	value_to_set = false;
	h_checked = false;
	i_checked = false;
	o_checked = false;
	c_checked = false;
	s_checked = false;
	l_checked = false;
	u_checked = false;
	e_checked = false;
	is_empty = false;
	err_bit = false;
	set_to_high = false;
}

void Arguments::Read_set_to_value(char* arg)
{
	if (!strcmp(arg, "0") ||
		!strcmp(arg, "false") ||
		!strcmp(arg, "low")) {
		set_to_high = false;
	}
	else if (!strcmp(arg, "1") ||
		!strcmp(arg, "true") ||
		!strcmp(arg, "high")) {
		set_to_high = true;
	}
	else
		err_bit = true;
}

void Arguments::Parsing_long_args(char * arg, unsigned &i)
{
	if (!strcmp(arg, "input"))
		i_checked = true;
	else if (!strcmp(arg, "output"))
		o_checked = true;
	else if (!strcmp(arg, "check"))
		c_checked = true;
	else if (!strcmp(arg, "set")) {
		s_checked = true;
		i++;
		Read_set_to_value(arg);
	}
	else if (!strcmp(arg, "status"))
		l_checked = true;
	else if (!strcmp(arg, "unexport"))
		u_checked = true;
	else if (!strcmp(arg, "export"))
		e_checked = true;
	else//if none of the above
		err_bit = true;
}

void Arguments::Parsing_short_args(char * arg, unsigned &i)
{
	if (*arg == 'i')/* chars is because I'm not sure how operator== wil handle*/
		h_checked = true;   /* the \0 char at the end. ie: ("i\0" =? 'i')             */
	else if (*arg == 'o')
		o_checked = true;
	else if (*arg == 'c')
		s_checked = true;
	else if (*arg == 's') {
		s_checked = true;
		i++;
		Read_set_to_value(arg);
	}
	else if (*arg == 'l')
		l_checked = true;
	else if (*arg == 'u')
		u_checked = true;
	else if (*arg == 'e')
		e_checked = true;
	else//if none of the above
		err_bit = true;
}

bool Arguments::Checking_for_h_checked(const char * arg)
{
	return (!strcmp(arg, "--help") || !strcmp(arg, "-h"));
}
