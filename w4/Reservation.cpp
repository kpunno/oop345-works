/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-10-09
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Reservation.h"

namespace sdds {

   // finds next delimiter in a string to be spliced
   size_t findNewPos(std::string& str, size_t pos, char delim);

   // trims of whitespace an extracted string
   void eraseWhiteSpace(std::string& str);

   Reservation::Reservation() {}

   void Reservation::update(int day, int time) {
      m_day = day;
      m_hour = time;
   }

   Reservation::Reservation(const std::string& res) {
      size_t pos{ 0 };
      std::string input = res;
      std::string temp{};

      pos = findNewPos(input, pos, ':');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);

      for (unsigned i = 0; i < temp.length(); i++) {
         m_id[i] = temp[i];
      }

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_name = temp;

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_email = temp;

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_partySize = stoi(temp);

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_day = stoi(temp);

      pos = findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      eraseWhiteSpace(temp);
      m_hour = stoi(temp);
   }

   std::ostream& operator<<(std::ostream& os, const Reservation res) {
      std::string occasion{};
      if (res.m_hour >= 6 && res.m_hour <= 9) {
         occasion = "Breakfast";
      }
      else if (res.m_hour >= 11 && res.m_hour <= 15) {
         occasion = "Lunch";
      }
      else if (res.m_hour >= 17 && res.m_hour <= 21) {
         occasion = "Dinner";
      }
      else {
         occasion = "Drinks";
      }
      os << "Reservation ";
      os << std::right;
      os << std::setw(10) << res.m_id << ": ";
      os << std::setw(20) << res.m_name << "  ";
      os << std::left;
      os << std::setw(24) << ("<" + res.m_email + ">");
      os << occasion + " on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_partySize;
      os << ((res.m_partySize > 1) ? " people." : " person.");
      os << std::endl;

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
