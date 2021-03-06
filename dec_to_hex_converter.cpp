
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <regex>

std::string dec_to_hex(int input) {
	std::map<int, std::string> hex;
	hex[10] = "A";
	hex[11] = "B";
	hex[12] = "C";
	hex[13] = "D";
	hex[14] = "E";
	hex[15] = "F";

	std::string output = "";
	std::vector <int> pow_16;
	std::vector <int> place_values;
	int remainder;

	for (int i = 1; i <= input; i *= 16) {
		pow_16.push_back(i);
	}

	for (int i = pow_16.size() - 1; i >= 0; i--) {
		if (input / pow_16[i] == 0) {
			place_values.push_back(input / pow_16[i]);
		}
		else {
			place_values.push_back(input / pow_16[i]);
			input = input % pow_16[i];
		}
	}

	for (int i = 0; i < place_values.size(); i++) {
		if (place_values[i] > 9) {
			output += hex[place_values[i]];
		}
		else {
			output += std::to_string(place_values[i]);
		}
	}
	
	return output;
}

int main()
{
	std::regex non_num("[\\D]{1,}");
	std::string decimal_str;
	int decimal;
	bool again = true;
	
	while (again == true) {
		std::cout << "Enter a decimal number, or press 'q' to quit: ";
		std::cin >> decimal_str;
		if (regex_match(decimal_str, non_num) && decimal_str != "q") {
			std::cout << "\n";
		}
		else if (decimal_str == "q"){
			std::cout << "\n";
			again = false;
		}
		else {
			decimal = std::stoi(decimal_str);
			std::cout << "\nHexadecimal equivalent of " << decimal << ": " << dec_to_hex(decimal) << "\n\n";

			}
		}
		
    return 0;
}

