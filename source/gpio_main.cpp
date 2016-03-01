#include "gpio.h"
#include "gpio_aux.h"

#include <string>

using namespace std;

int main(int argc, char** argv){
	string gpio_num;
	bool as_input;
	if (parse_args(argc, argv, gpio_num, as_input))//if parse_args returns 1 a failed state
		return 1;
	//DO IMPORTANT STUFF
	return 0;
}
