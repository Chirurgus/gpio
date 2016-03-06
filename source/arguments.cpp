#include "arguments.h"
#include <cstdlib>

Arguments::Arguments(int argc, char** argv) {
	//If no arguments are provided(appart from the command name, and gpio num)
	if (argc <= 2) {
		is_empty = true;
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

void Arguments::Read_set_to_value(char* arg)
{
	if (arg == "0" ||
		arg == "false" ||
		arg == "low") {
		set_to_high = false;
	}
	else if (arg == "1" ||
		arg == "true" ||
		arg == "high") {
		set_to_high = true;
	}
	else
		err_bit = true;
}

void Arguments::Parsing_long_args(char * arg, unsigned &i)
{
	if (arg == "help")
		h_checked = true;
	else if (arg == "input")
		i_checked = true;
	else if (arg == "output")
		o_checked = true;
	else if (arg == "check")
		c_checked = true;
	else if (arg == "set") {
		s_checked = true;
		i++;
		Read_set_to_value(arg);
	}
	else if (arg == "status")
		l_checked = true;
	else if (arg == "unexport")
		u_checked = true;
	else if (arg == "export")
		e_checked = true;
	else//if none of the above
		err_bit = true;
}

void Arguments::Parsing_short_args(char * arg, unsigned &i)
{
	if (arg == "h")
		h_checked = true;   /* Comment: the reason why i check for strings and not    */
	else if (arg == "i")/* chars is because I'm not sure how operator== wil handle*/
		h_checked = true;   /* the \0 char at the end. ie: ("i\0" =? 'i')             */
	else if (arg == "o")
		o_checked = true;
	else if (arg == "c")
		s_checked = true;
	else if (arg == "s") {
		s_checked = true;
		i++;
		Read_set_to_value(arg);
	}
	else if (arg == "l")
		l_checked = true;
	else if (arg == "u")
		u_checked = true;
	else if (arg == "e")
		e_checked = true;
	else//if none of the above
		err_bit = true;
}
