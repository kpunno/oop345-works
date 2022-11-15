/*
-- WORKSHOP 6 --

Name----Kristjan Punno
Email-- - kpunno@myseneca.ca
ID------ 150695211
Section - NCC
Date---- 2022 - 11 - 06
+ ---------------------------------------------------------------------- +
| I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments. |
+---------------------------------------------------------------------- +
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include "CrimeStatistics.h"

namespace sdds {

   CrimeStatistics::CrimeStatistics(const char* filename) {
      std::ifstream file(filename);

      if (!file) {
         std::cerr << "File does not exist!" << std::endl;
      }
      while (file) {
         std::string line;
         std::getline(file, line);

         if (line.length()) {
            Crime crime;

            crime.m_province = splice(line, 25);
            crime.m_district = splice(line, 25);
            crime.m_crime = splice(line, 25);

            try {
               crime.m_year = std::stoi(splice(line, 5));
               crime.m_cases = std::stoi(splice(line, 5));
               crime.m_resolved = std::stoi(splice(line, 5));

               m_crimes.push_back(crime);
            }
            catch (...) {
               std::cerr << "Invalid record!" << std::endl;
            }
         }
      }
   }


   void CrimeStatistics::display(std::ostream& out) const {

      std::for_each(cbegin(m_crimes), cend(m_crimes), [=,&out](const Crime crime)
         { out << crime << std::endl; });

      out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');

      auto cases = std::accumulate(m_crimes.begin(), m_crimes.end(), 0, [=](int i, const Crime crime)
         { return crime.m_cases + i; });

      auto resolved = std::accumulate(m_crimes.begin(), m_crimes.end(), 0, [=](int i, const Crime crime)
         { return crime.m_resolved + i; });

      out << std::right;
      out << "| " << std::setw(84) << ("Total Crimes:  " + std::to_string(cases)) << " |" << std::endl;
      out << "| " << std::setw(84) << ("Total Resolved Cases:  " + std::to_string(resolved)) << " |" << std::endl;
   }

   void CrimeStatistics::sort(const char* category) {
      if (std::string(category) == "Province") {
         std::sort(begin(m_crimes), end(m_crimes), [](const Crime lhs, const Crime rhs)
            { return lhs.m_province < rhs.m_province; });
      }
      else if (std::string(category) == "Crime") {
         std::sort(begin(m_crimes), end(m_crimes), [](const Crime lhs, const Crime rhs)
            { return lhs.m_crime < rhs.m_crime;; });
      }
      else if (std::string(category) == "Cases") {
         std::sort(begin(m_crimes), end(m_crimes), [](const Crime lhs, const Crime rhs)
            { return lhs.m_cases < rhs.m_cases; });
      }
      else if (std::string(category) == "Resolved") {
         std::sort(begin(m_crimes), end(m_crimes), [](const Crime lhs, const Crime rhs)
            { return lhs.m_resolved < rhs.m_resolved; });
      }
   }

   void CrimeStatistics::cleanList() {

      std::transform(begin(m_crimes), end(m_crimes), begin(m_crimes), [=](Crime crime) { 
         if (crime.m_crime == "[None]") { 
            crime.m_crime.erase();
         } 
         return crime;
      });
   }


   bool CrimeStatistics::inCollection(const char* string) const {

      bool match = std::any_of(begin(m_crimes), end(m_crimes), [=](const Crime crime)
         { return crime.m_crime == string ? true : false; });

      return match;
   }


   std::list<Crime> CrimeStatistics::getListForProvince(const char* province) const {

      size_t size = std::count_if(begin(m_crimes), end(m_crimes), [=](const Crime crime)
         { return (crime.m_province == province) ? true : false; });

      std::list<Crime> provincialList(size);

      std::copy_if(begin(m_crimes), end(m_crimes), begin(provincialList), [=](const Crime crime)
         { return (crime.m_province == province) ? true : false;});

      return provincialList;
   }

   // *** HELPERS *** //

   std::ostream& operator<<(std::ostream& out, const Crime& crime) {
      out << std::left << "| ";
      out << std::setw(21) << crime.m_province << " | ";
      out << std::setw(15) << crime.m_district << " | ";
      out << std::setw(20) << crime.m_crime << " | ";
      out << std::right;
      out << std::setw(6) << crime.m_year << " | ";
      out << std::setw(4) << crime.m_cases << " | ";
      out << std::setw(3) << crime.m_resolved << " |";

      return out;
   }

   std::string splice(std::string& line, size_t length) {
      std::string output = line.substr(0, length);
      eraseWhiteSpace(output);
      line.erase(0, length);
      return output;
   }

   void eraseWhiteSpace(std::string& str) {
      unsigned int i = 0;
      if (str != "") {
         while (str[i] == ' ') {
            str.erase(i, 1);
         }
         if (str.length() != 0) {
            i = str.length() - 1;
            while (str[i] == ' ') {
               str.erase(i--, 1);
            }
         }
      }
   }

}