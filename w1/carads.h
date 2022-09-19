/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-09-18
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

#ifndef CAR_ADS_H_
#define CAR_ADS_H_

#include <istream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {

	// lists command line arguments
	extern void listArgs(int argc, char* argv[]);

	class Cars {
	private:
		char* m_brand = nullptr;
		char m_model[16]{};
		int m_year{};
		double m_price{};
		char m_wear{};
		bool m_discount{};

	public:

		// default constructor
		Cars();

		// copy assignment operator
		Cars& operator=(const Cars& car);

		// copy constructor
		Cars(const Cars& car);

		// destructor deletes allocated memory
		~Cars();

		//reads one entry of car details from text file
		std::istream& read(std::istream& is);

		//formatted display of an instance of Cars
		void display(bool reset);

		//returns the wear status of car -- new 'N', or used 'U'
		char getStatus() const;

		// returns true if a car is new 'N', false if used 'U'
		operator bool() const;
	};

	// operator loads a Cars object with data from istream
	std::istream& operator>>(std::istream& is, Cars& car);

	// operator overload uses copy assignment for Cars objects
	void operator>>(const Cars& car1, Cars& car2);
}

#endif