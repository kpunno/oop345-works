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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "carads.h"

double g_taxrate = 0;
double g_discount = 0;

namespace sdds {

	void listArgs(int argc, char* argv[]) {
		std::cout << "Command Line:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (int i = 0; i < argc; i++) {
			std::cout << "  " << (i + 1) << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------" << std::endl << std::endl;
	}

	Cars::Cars(){}

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
			std::string buffer;

			m_wear = is.get();

			is.get();

			// copy brand string -> buffer
			std::getline(is, buffer, ',');

			// delete present memory -> allocate new memory and copy string
			delete[] m_brand;
			m_brand = new char[buffer.length() + 1];
			strcpy(m_brand, buffer.c_str());

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

		static int counter = 0;
		double price = m_price + (m_price * g_taxrate);

		if (reset) {
			counter = 0;
		}

		std::cout << std::setw(2) << std::left << std::fixed << ++counter << std::setw(2) << ".";
		if (this->m_brand) {
			std::cout <<
				std::setw(10) << m_brand << std::setw(2) << "|" <<
				std::setw(15) << m_model << std::setw(2) << "|" <<
				std::setw(5) <<  m_year << "|" <<
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