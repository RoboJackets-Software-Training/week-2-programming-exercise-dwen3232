#pragma once
#include <iostream>
#include <vector>

class NumberConverter {
public:
	NumberConverter();
	NumberConverter(std::vector<double> fields);
	// NumberConverter(int binary_inputs, int decimal_inputs, int hex_inputs,
	// 	int binary_outputs, int decimal_outputs, int hex_outputs);
	int hexCharToNumber(char input);
	char numberToHexChar(int input);
	void print_fields();
	int binary_inputs;
	int decimal_inputs;
	int hex_inputs;
	int binary_outputs;
	int decimal_outputs;
	int hex_outputs;
};