#include "gpio_aux.h"

#include <string>
#include <iostream>

using namespace std;

int parse_args(int argc, char** argv, const string &gpio_num, bool as_input){
	if (argc <= 1){
		cout << "What do you want to do with gpio?\n";
		return 1;//The program has nothing to do.
	}
	for (unsinged i = 1; i < argc; i++){
		if (*(argv[i]) == '-'
	}
}
