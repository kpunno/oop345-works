/*
==============
= WORKSHOP 6 =
==============

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

#include <string>
#include <sstream>

#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"

namespace sdds {

   Vehicle* createInstance(std::istream& is) {

      Vehicle* vehicle = nullptr;

      if (is.peek() != -1) {

         std::string line{};

         // gets first non-blank character of the input stream
         // validates that the character is a valid character representation of:
         // a car, racecar, van or luxuryvan
         // throws a exception if no matching character was found

         std::getline(is, line, '\n');
         std::istringstream sstream(line);
         eraseWhiteSpace(line);

         if (line[0] == 'c' || line[0] == 'C')
            vehicle = new Car(sstream);

         else if (line[0] == 'v' || line[0] == 'V')
            vehicle = new Van(sstream);

         else if (line[0] == 'r' || line[0] == 'R')
            vehicle = new Racecar(sstream);

         else if (line[0] == 'l' || line[0] == 'L')
            vehicle = new Luxuryvan(sstream);

         else {
            vehicle = nullptr;
            line = line[0];
            throw(std::string("Unrecognized record type: [" + line + "]"));
         }
      }
      return vehicle;
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
