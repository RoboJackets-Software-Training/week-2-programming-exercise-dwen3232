#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "NumberConverter.h"


std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int binaryToDecimal(std::string s, NumberConverter &converter) {
  int decimal = 0;
  for (int i = 0; i < s.size(); i++) {
    int place_value = converter.hexCharToNumber(s[s.size()-1-i]);
    decimal += std::pow(2, i) * place_value;
  }
  converter.binary_inputs++;
  converter.decimal_outputs++;
  return decimal;
}

int hexToDecimal(std::string s, NumberConverter &converter) {
  int decimal = 0;
  for (int i = 0; i < s.size(); i++) {
    int place_value = converter.hexCharToNumber(s[s.size()-1-i]);
    decimal += std::pow(16, i) * place_value;
  }
  converter.hex_inputs++;
  converter.decimal_outputs++;
  return decimal;
}

std::string decimalToHex(int s, NumberConverter &converter) {
  if (s == 0) {
    return "0";
  }
  std::string hex = "";
  while (s != 0) {
    hex = converter.numberToHexChar(s % 16) + hex;
    s /= 16;
  }
  converter.decimal_inputs++;
  converter.hex_outputs++;
  return hex;
}

std::string binaryToHex(std::string s, NumberConverter &converter) {
  if (s.compare("0") == 0) {
    return "0";
  }
  std::string hex = "";
  int bit_value = 0;
  int bit_counter = 0;
  for (int i = 0; i < s.size(); i++) {
    bit_value += std::pow(2, bit_counter++) * converter.hexCharToNumber(s[s.size()-1-i]);
    if (bit_counter == 4 || i == s.size() - 1) {
      hex = converter.numberToHexChar(bit_value) + hex;
      bit_value = 0;
      bit_counter = 0;
    }
  }
  converter.binary_inputs++;
  converter.hex_outputs++;
  return hex;
}

std::string decimalToBinary(int s, NumberConverter &converter) {
  if (s == 0) {
    return "0";
  }
  std::string hex = "";
  while (s != 0) {
    hex = converter.numberToHexChar(s % 2) + hex;
    s /= 2;
  }
  converter.decimal_inputs++;
  converter.binary_outputs++;
  return hex;
}

std::string hexToBinary(std::string s, NumberConverter &converter) {
  if (s.compare("0") == 0) {
    return "0";
  }
  std::string binary = "";
  for (int i = 0; i < s.size(); i++) {
    int value = converter.hexCharToNumber(s[s.size()-1-i]);
    for (int j = 0; j < 4; j++) {
      binary = converter.numberToHexChar(value % 2) + binary;
      value /= 2;
    }
  }
  converter.hex_inputs++;
  converter.binary_outputs++;
  return binary;
}

int main() {
  
  // std::string test_binary = "101101101";
  // std::string test_hex = "F102F";
  // int test_decimal = 987183;

  // std::cout << binaryToDecimal(test_binary, converter) << std::endl;
  // std::cout << hexToDecimal(test_hex, converter) << std::endl;

  // std::cout << decimalToHex(test_decimal, converter) << std::endl;
  // std::cout << binaryToHex(test_binary, converter) << std::endl;

  // std::cout << decimalToBinary(test_decimal, converter) << std::endl;
  // std::cout << hexToBinary(test_hex, converter) << std::endl;
  std::string output;
  std::string output_type;
  std::string input;
  std::string s;

  std::cin >> s;
  std::vector<double> fields = readInVector(s);
  NumberConverter converter(fields);
  std::cin >> output_type;
  std::cin >> input;
  
  if (output_type.compare("b") == 0) {
    if (input.substr(0, 1).compare("b") == 0) {
      std::cout << "redundant case!" << std::endl;
    } else if (input.substr(0, 2).compare("0x") == 0) {
      input = input.substr(2);
      output = hexToBinary(input, converter);
    } else {
      output = decimalToBinary(std::stoi(input), converter);
    }

  } else if (output_type.compare("d") == 0) {
    if (input.substr(0, 1).compare("b") == 0) {
      input = input.substr(1);
      output = std::to_string(binaryToDecimal(input, converter));
    } else if (input.substr(0, 2).compare("0x") == 0) {
      input = input.substr(2);
      output = std::to_string(hexToDecimal(input, converter));
    } else {
      std::cout << "redundant case!" << std::endl;
    }

  } else if (output_type.compare("h") == 0) {
    std::string prefix = input.substr(0, 2);
    if (input.substr(0, 1).compare("b") == 0) {
      input = input.substr(1);
      output = binaryToHex(input, converter);
    } else if (input.substr(0, 2).compare("0x") == 0) {
      std::cout << "redundant case!" << std::endl;
    } else {
      output = decimalToHex(std::stoi(input), converter);
    }

  } else {
    std::cout << "invalid output type" << std::endl;
  }
  std::cout << "input: " << input << std::endl;
  std::cout << "output type: " << output_type << std::endl;
  std::cout << "result: " << output << std::endl;
  converter.print_fields();
}
