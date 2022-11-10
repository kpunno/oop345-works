
#include <iostream>
#include <fstream>
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
               crime.m_noCases = std::stoi(splice(line, 5));
               crime.m_noResolved = std::stoi(splice(line, 5));

               m_crimes.push_back(crime);
            }
            catch (...) {
               std::cerr << "Invalid record!" << std::endl;
            }
         }
      }
   }

   auto CrimeStatistics::display(std::ostream& out)->void const {
      for (auto it = m_crimes.begin(); it != m_crimes.end(); ++it) {
         out << *it << std::endl;
      }
   }

   auto operator<<(std::ostream& out, const Crime& crime)->std::ostream& {
      out << std::left << "| ";
      out << std::setw(21) << crime.m_province << " | ";
      out << std::setw(15) << crime.m_district << " | ";
      out << std::setw(20) << crime.m_crime << " | ";
      out << std::right;
      out << std::setw(6) << crime.m_year << " | ";
      out << std::setw(4) << crime.m_noCases << " | ";
      out << std::setw(3) << crime.m_noResolved << " |";

      return out;
   }

   auto splice(std::string& line, size_t length)->std::string {
      std::string output = line.substr(0, length);
      eraseWhiteSpace(output);
      line.erase(0, length);
      return output;
   }

   auto eraseWhiteSpace(std::string& str)->void {
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
