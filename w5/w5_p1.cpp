// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
		std::fstream file;
		file.open(argv[1]);
		if (file.is_open()) {
			std::string line;

			constexpr int size = sizeof(library) / sizeof(library[0]); // size of array

			for (unsigned i{0}, j{0}; j < size; i++) {
				std::getline(file, line);
				if (line[0] != '#') {
					library[j] = line;
					j++;
				}
			}
		}
		else {
			std::cerr << "ERROR: File does not exist" << std::endl;
			exit(AppErrors::CannotOpenFile);
		}
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object

	auto priceConversion = [&](Book& book) {
		if (book.country() == "US") {
			book.price() *= usdToCadRate;
		}
		else if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) {
			book.price() *= gbpToCadRate;
		}
		return book;
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";

	for (auto elm : library)
		std::cout << elm;

	std::cout << "-----------------------------------------\n\n";

	for (Book& elm : library)
		elm = priceConversion(elm);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";

	for (auto elm : library)
		std::cout << elm;

	std::cout << "-----------------------------------------\n";

	return 0;
}
