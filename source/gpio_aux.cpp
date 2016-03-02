#include "gpio_aux.h"

#include <string>
#include <iostream>

using namespace std;

int parse_args(int argc, char** argv, string &gpio_num, bool &as_input){
	if (argc <= 1){
		cout << "What do you want to do with gpio?\n";
		return 1;//The program has nothing to do.
	}
	for (unsigned i = 1; i < argc; i++){
		if (*(argv[i]) == '-') {// Read arguments with '-' in front of them.
			if (*(++argv[i]) == '-') {//Read explicit long arguments.
				argv[i]++;
				if (argv[i] == "help")
					;//TODO: show help menu
				else if (argv[i] == "input")
					;//TODO: do whatever if -i flag is checked
				else if (argv[i] == "output")
					;//TODO: do whatever if -o flag is checked
				else if (argv[i] == "status")
					;//TODO do whatever if -s flag is checked
				else
					;//TODO: scream at the user that his/her arguments are stupid
			}
			else {
				while (*(++argv[i]) != '\0') {
					if (*(argv[i]) == 'i')
						as_input = true;
					if (*(argv[i]) == )
				}
			}
		}
		else {

		}
		
		

	}
}
//gpio -i *GPIO_NUM* => print 0, or 1
//gpio -o -h *GPIO_num* => set GPIO_num to hgih
//gpio -o -l *GPIO_num* => set GPIO_num to low
//gpio -s => print all GPIO staus

//gpio *gpio_num* 1
//gpio *gpio_num*
//gpio -s
