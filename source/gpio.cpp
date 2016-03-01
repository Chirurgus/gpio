#include "gpio.h"

#include <string>
#include <iostream>
#include <fstream>

GPIO::GPIO(): _gpionum("2") { }

GPIO::GPIO(const std::string &num ): _gpionum(num) { }

int GPIO::export_gpio() {
	std::string path = "/sys/class/gpio/export";
	std::ofstream export_stream(path.c_str());
	if (export_stream < 0) {
		std::cout << "Unable to export GPIO " << this->_gpionum << "." << std::endl;
		return -1;
	}
	export_stream << this->_gpionum;
	export_stream.close();
	return 0;
}

int GPIO::unexport_gpio() {
	std::string path = "/sys/class/gpio/unexport";
	std::ofstream unexport_stream(path.c_str());
	if ( unexport_stream < 0 ) {
 		std::cout << "Unable to unexport GPIO "+ this->_gpionum+"." <<std::endl;
		return -1;
	}
	unexport_stream << this->_gpionum;
 	unexport_stream.close();
	return 0;
} 

int GPIO::set_direction_out(){
	std::string path = "/sys/class/gpio/gpio" + this->_gpionum + "/direction";
	std::ofstream set_direction_stream(path.c_str());
	if ( set_direction_stream < 0  ){
		std::cout << "Unable to set direction for GPIO " + this->_gpionum + "." << std::endl;
		return -1;
	}
	set_direction_stream << "out";
	set_direction_stream.close();
}

int GPIO::set_direction_in(){
	std::string path = "/sys/class/gpio/gpio" + this->_gpionum + "/direction";
	std::ofstream set_direction_stream(path.c_str());
	if ( set_direction_stream < 0  ){
		std::cout << "Unable to set direction for GPIO " + this->_gpionum + "." << std::endl;
		return -1;
	}
	set_direction_stream << "in";
	set_direction_stream.close();
}
	
int GPIO::set_state_high(){
	std::string path = "/sys/class/gpio/gpio" + this->_gpionum + "/value";
	std::ofstream set_direction_stream(path.c_str());
	if ( set_direction_stream < 0  ){
		std::cout << "Unable to set direction for GPIO " + this->_gpionum + "." << std::endl;
		return -1;
	}
	set_direction_stream << "1";
	set_direction_stream.close();
}

int GPIO::set_state_low(){
	std::string path = "/sys/class/gpio/gpio" + this->_gpionum + "/value";
	std::ofstream set_direction_stream(path.c_str());
	if ( set_direction_stream < 0  ){
		std::cout << "Unable to set direction for GPIO " + this->_gpionum + "." << std::endl;
		return -1;
	}
	set_direction_stream << "0";
	set_direction_stream.close();
}

int GPIO::check_state(){
	int val;
	std::string path = "/sys/class/gpio/gpio" + this->_gpionum + "/value";
	std::ifstream get_value_stream(path.c_str());
	if  ( get_value_stream < 0 ){
		std::cout << "Unable to chek value for GPIO " + this->_gpionum + "." << std::endl;
		return -1;
	}
	get_value_stream >> val;
	return val != 0 ? 1 : 0;
}
