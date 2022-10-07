/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-10-03
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/


#include <string>
#include "Utils.h"

namespace sdds {
   void Utils::eraseWhiteSpace(std::string& str) {
      unsigned int i = 0;
      while (str[i] == ' ') {
         str.erase(i, 1);
      }
      i = str.length() - 1;
      while (str[i] == ' ') {
         str.erase(i--, 1);
      }
      
   }

   size_t Utils::findNewPos(std::string& str, size_t pos, char delim) {
      str.erase(0, pos);
      pos = str.find(delim);
      return pos;
   }

   std::string& Utils::extractNext(size_t pos, std::string& input) {
      std::string temp;
      pos = Utils::findNewPos(input, pos, ',');
      temp = input.substr(0, pos++);
      Utils::eraseWhiteSpace(temp);
      return temp;
   }
}
