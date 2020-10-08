#include "NumberConverter.h"

NumberConverter::NumberConverter() {
	binary_inputs = 0;
	decimal_inputs = 0;
	hex_inputs = 0;
	binary_outputs = 0;
	decimal_outputs = 0;
	hex_outputs = 0;
}

NumberConverter::NumberConverter(std::vector<double> fields) {
	decimal_inputs = fields[0];
	binary_inputs = fields[1];
	hex_inputs = fields[2];
	decimal_outputs = fields[3];
	binary_outputs = fields[4];
	hex_outputs = fields[5];	
}
int NumberConverter::hexCharToNumber(char input) {
  if (input > 57) {
  	return input - (65 - 10);
  } else {
  	return input - 48;
  }
}

char NumberConverter::numberToHexChar(int input) {
  if (input < 10) {
  	return input + 48;
  } else {
  	return (input - 10) + 65;
  }
}

void NumberConverter::print_fields() {
	std::cout << "decimal_inputs: " << decimal_inputs << std::endl;
	std::cout << "binary_inputs: " << binary_inputs << std::endl;
	std::cout << "hex_inputs: " << hex_inputs << std::endl;
	std::cout << "decimal_outputs: " << decimal_outputs << std::endl;
	std::cout << "binary_outputs: " << binary_outputs << std::endl;
	std::cout << "hex_outputs: " << hex_outputs << std::endl;
}