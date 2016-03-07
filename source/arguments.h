#ifndef GUARD_ARGUMENTS_H
#define GUARD_ARGUMENTS_H

#include <string>

class Arguments {
public:
	Arguments(int argc, char** argv);
	void Check();

	bool value_to_set,//true is 1, false is 0
		h_checked,//Help, Do this one frst 
		i_checked,//Input 
		o_checked,//Output 
		c_checked,//Check - read gpio value 
		s_checked,//Set 
		l_checked,//Status - List  then this one
		u_checked,//Unexport 
		e_checked,//Export 
		is_empty,
		err_bit,
		set_to_high;
	std::string gpio_num;

private:
	void Set_all_to_false();
	void Read_set_to_value(char* arg);
	void Parsing_long_args(char* arg, unsigned &i);
	void Parsing_short_args(char* arg, unsigned &i);
	bool Checking_for_h_checked(const char* arg);
};
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
