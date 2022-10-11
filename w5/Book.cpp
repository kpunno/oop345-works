/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-10-10
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

#include <iostream>
#include <iomanip>
#include "Book.h"

namespace sdds {

   void eraseWhiteSpace(std::string& str);

   size_t findNewPos(std::string& str, size_t pos, char delim);

   Book::Book() {}

   Book::Book(const std::string& strBook) {
      size_t pos{0};
      std::string input{strBook};
      std::string temp{};

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_author = temp;

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_title = temp;

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_country = temp;

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_price = stod(temp);

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_year = stoi(temp);

      pos = findNewPos(input, pos, '\n');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_desc = temp;
   }

   const std::string& Book::title() const {
      return m_title;
   }

   const std::string& Book::country() const {
      return m_country;
   }

   const size_t& Book::year() const {
      return m_year;
   }

   double& Book::price() {
      return m_price;
   }


   // UTILITY HELPERS //

   std::ostream& operator<<(std::ostream& os, Book& book) {
      if (book.m_title != "") {
         os << std::right;

         os << std::setw(20) << book.m_author << " | ";
         os << std::setw(22) << book.m_title << " | ";
         os << std::setw(5) << book.m_country << " | ";
         os << std::setw(4) << book.m_year << " | ";
         os << std::fixed << std::setprecision(2);
         os << std::setw(6) << book.m_price << " | ";
         os << std::left;
         os << std::setw(22) << book.m_desc;

         os << std::endl;
      }
      return os;
   }

   void eraseWhiteSpace(std::string& str) {
      unsigned int i = 0;
      while (str[i] == ' ') {
         str.erase(i, 1);
      }
      i = str.length() - 1;
      while (str[i] == ' ') {
         str.erase(i--, 1);
      }
   }
   size_t findNewPos(std::string& str, size_t pos, char delim) {
      str.erase(0, pos);
      pos = str.find(delim);
      return pos;
   }
}
