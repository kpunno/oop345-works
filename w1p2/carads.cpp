#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "carads.h"


double g_taxrate = 0;
double g_discount = 0;

namespace sdds {

	// lists arguments received by command line
	// saves filenames within cars class
	void listArgs(int argc, char* argv[]) {
		std::cout << "Command Line:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (int i = 0; i < argc; i++) {
			std::cout << "  " << (i + 1) << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------" << std::endl << std::endl;
	}

	Cars::Cars() {
		m_brand = nullptr;
	}

	Cars& Cars::operator=(const Cars& car) {
		if (this != &car) {
			delete[] m_brand;
			m_brand = new char[strlen(car.m_brand) + 1];
			strcpy(m_brand, car.m_brand);
		}
		strcpy(m_model, car.m_model);
		m_discount = car.m_discount;
		m_price = car.m_price;
		m_wear = car.m_wear;
		m_year = car.m_year;

		return *this;
	}

	Cars::Cars(const Cars& car) {
		delete[] m_brand;
		m_brand = new char[strlen(car.m_brand) + 1];
		strcpy(m_brand, car.m_brand);
		strcpy(m_model, car.m_model);
		m_discount = car.m_discount;
		m_price = car.m_price;
		m_wear = car.m_wear;
		m_year = car.m_year;
	}

	Cars::~Cars() {
		delete[] m_brand;
		m_brand = nullptr;
	}

	std::istream& Cars::read(std::istream& is) {
		if (is.good()) {
			// char buffer
			char temp[100]{};

			

			m_wear = is.get();
			is.get();
			is.getline(temp, 1000, ',');
			delete[] m_brand;
			m_brand = new char[strlen(temp) + 1];
			strcpy(m_brand, temp);
			is.getline(m_model, 1000, ',');
			is >> m_year;
			is.get();
			is >> m_price;
			is.get();
			m_discount = is.get() == 'Y' ? true : false;
			is.ignore(1000, '\n');
		}
		return is;
	}

	void Cars::display(bool reset) {

		static int counter;
		double price = m_price + (m_price * g_taxrate);

		if (reset) {
			counter = 0;
		}
		std::cout << std::setw(2) << std::left << std::fixed << ++counter << ". ";
		if (this->m_brand) {
			std::cout <<
				std::setw(10) << m_brand << "|" <<
				std::setw(16) << m_model << "| " <<
				std::setw(4) << m_year << " |" <<
				std::setw(12) << std::right << std::setprecision(2) << (price) << "|";
			if (m_discount) {
				std::cout << std::setw(12) << (price - (price * g_discount));
			}
			std::cout << std::endl;
		}
		else std::cout << "No Car" << std::endl;

	}

	char Cars::getStatus() const {
		return m_wear;
	}

	Cars::operator bool() const {
		return m_wear == 'N' ? true : false;
	}

	std::istream& operator>>(std::istream& is, Cars& car) {
		return car.read(is);
	}

	void operator>>(const Cars& car1, Cars& car2) {
		car2 = car1;
	}

}