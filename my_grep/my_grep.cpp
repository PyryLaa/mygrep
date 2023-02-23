#include <iostream>
#include <string> //For string handling
#include <fstream> //File handling
#include <algorithm> //For character case conversion
#include <stdarg.h> //For handling variable amount of arguments


void str_search(std::string*, std::string*); //Function for searching another string from a string
void input_search();//If no additional arguments given, program goes to this function
void file_search(int arg_c, ...);//If given search string and file name, go here

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "fi_FI"); //Enable the use of ä and ö

	

	if (argc == 2 || argc > 4) {
		
		std::cout << "Usage: If you give no arguments, program will ask you to give string and then another string to search from the first"
			<< "\nAccepted arguments (give in this order): <search options> <search string> <filename>"
			<< "\nAccepted file extension is .txt"
			<< "\nAccepted search options (these are optional): <-ol> <-oo> <-olo>"
			<< "\n<-ol> gives you the count from which line the string is found"
			<< "\n<-oo> gives you the count of lines where the string is found"
			<< "\n<-olo> gives you both counts";
		
	}
	else if (argc == 1) {//If no other argumens than program name is given, run this
		input_search();
	}
	else if (argc == 3) { //If only search string and file from which to search is given
		std::string search_str = argv[1], filename = argv[2];
		file_search(argc, filename, search_str);
	}
	else if (argc == 4) { //If other options are given for searching
		std::string option_str = argv[1], search_str = argv[2], filename = argv[3];
		file_search(argc, filename, search_str, option_str);
	}
	return 0;
}


void input_search() { //If no args given when starting the program, goes here. Asks user for two strings and searches the other with the other
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
void file_search(int arg_c, ...) { //Searches the given file for the given string, additional options include line count in the file and count of found lines
	va_list argl; //This is the list of arguments, va_list enables the use of variable amount of arguments to a function
	va_start(argl, arg_c);

	std::string fname;
	std::string srch;
	std::string srch_opt;

	switch (arg_c) { //Here we parse the additional arguments given to the function
		case(3): {
			 fname = va_arg(argl, std::string);
			 srch = va_arg(argl, std::string);
			 break;
		}
		case(4): {
			fname = va_arg(argl, std::string);
			srch = va_arg(argl, std::string);
			srch_opt = va_arg(argl, std::string);
			break;
		}
	}
	va_end(argl);

	int opt_case = 0; //

	if (srch_opt == "-ol") {
		opt_case = 1;
	}
	else if (srch_opt == "-oo") {
		opt_case = 2;
	}
	else if (srch_opt == "-olo") {
		opt_case = 3;
	}
	
	std::ifstream filein;
	std::string line;
	std::size_t found;
	unsigned int lcounter = 0, fcounter = 0;
	bool in_text = false;

	try {
		
		filein.open(fname);
		std::string exception = "File cannot be opened";
		if (!filein.good()) {
			throw exception;
		}
	}
	catch (std::string exception) {
		std::cout << exception;
	}

	if (filein.good()) {
		//std::cout << "File " << fname << " is open.";
		while (std::getline(filein, line)) {

			found = line.find(srch);
			if (opt_case == 1 || opt_case == 3) {
				lcounter++;
			}
		

			if (found != std::string::npos) {

				if (opt_case == 2 || opt_case == 3) {
					fcounter++;
				}

				if (lcounter == 0) {
					std::cout << line <<'\n';
				}
				else {
					std::cout << lcounter << ':' << line << '\n';
				}
				in_text = true;
			}
			
		}

		if (in_text == false) {
			std::cout << '"' << srch << '"' << " not found in " << fname;
		}
		if (opt_case == 2 || opt_case == 3 && in_text == true) {
			std::cout << "Count of occurences: " << fcounter;
		}
		
	}
	filein.close();
}

