#include <iostream>
#include <string>
#include <fstream>

void str_search(std::string*, std::string*);

int main(){

	std::string usr_in, search;
	std::string* input_ptr, * search_ptr;
	std::cout << "Give a string from which to search for: ";
	std::getline(std::cin, usr_in);
	std::cout << "Give search string: ";
	std::getline(std::cin, search);

	if (search.length() > usr_in.length()) { //Test if the search string is longer than the input string
		std::cout << "Search string too long, give new search string: ";
		std::getline(std::cin, search);
	}

	input_ptr = &usr_in;
	search_ptr = &search;
	str_search(input_ptr, search_ptr);
	
	return 0;
}

void str_search(std::string* input, std::string* searcher) { //Function for searching the string in the input string
	std::string inputstr = *input, searchstr = *searcher;
	std::size_t found = inputstr.find(searchstr);

	if (found != std::string::npos) {
		std::cout << '"' << searchstr << '"' << " found in " << '"' << inputstr << '"' << " in position " << found;
	}
	else {
		std::cout << '"' << searchstr << '"' << " NOT found in " << '"' << inputstr << '"';
	}

}