//For now, this program will ask for a string from the user and then ask another string to search from the first given string

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

void str_search(std::string*, std::string*); //Function for searching another string from a string
void input_search();//If no additional arguments given, program goes to this function
void file_search(std::string, std::string);//If given search string and file name, go here

int main(int argc, char* argv[]) {
	
	if (argc == 1) {//If no other argumens than program name is given, run this
		input_search();
	}
	else if (argc >= 2) {
		std::string search_str = argv[1], filename = argv[2];
		file_search(search_str, filename);
	}
	return 0;
}


void input_search() {
	std::string usr_in, search;
	std::string* input_ptr, * search_ptr;
	char case_s;

	std::cout << "Give a string from which to search for: ";
	std::getline(std::cin, usr_in);
	std::cout << "Give search string: ";
	std::getline(std::cin, search);

	std::cout << "Do you want the search to be case-sensitive?(Y/N): ";
	std::cin >> case_s;

	while (search.length() > usr_in.length()) { //Test if the search string is longer than the input string
		std::cout << "Search string too long, give new search string: ";
		std::getline(std::cin, search);
	}

	if (case_s == 'N' || case_s == 'n') { //Converts the input and search strings to uppercase if case-sensitivity is not chosen
		std::transform(usr_in.begin(), usr_in.end(), usr_in.begin(), ::toupper);
		std::transform(search.begin(), search.end(), search.begin(), ::toupper);
	}

	input_ptr = &usr_in; //Pointer to user input, will be passed to search function
	search_ptr = &search; //Pointer to search string, will be passed to search function

	str_search(input_ptr, search_ptr);
	
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
void file_search(std::string srch, std::string fname) {
	std::ifstream filein;
	std::string line;
	std::size_t found;
	bool in_text = false;
	filein.open(fname);

	if (filein.good()) {
		//std::cout << "File " << fname << " is open.";
		while (std::getline(filein, line)) {

			found = line.find(srch);

			if (found != std::string::npos) {
				std::cout << line << '\n';
				in_text = true;
			}
		}
		if (in_text == false) {
			std::cout << '"' << srch << '"' << " not found in " << fname;
		}
		
	}
	else {
		std::cout << "File " << fname << " cannot be opened.";
	}
	filein.close();

	

}

