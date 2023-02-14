#include <iostream>
#include <string>
#include <fstream>

int main(){

	std::string usr_in, search;
	std::cout << "Give a string from which to search for: ";
	std::getline(std::cin, usr_in);
	std::cout << "Give search string: ";
	std::getline(std::cin, search);

	std::size_t found = usr_in.find(search);

	if (found != std::string::npos) {
		std::cout << '"' << search << '"' << "found in" << '"' << usr_in << '"' << "in position " << found;
	}
	else {
		std::cout << '"' << search << '"' << "NOT found in " << '"' << usr_in << '"';
	}
	return 0;
}