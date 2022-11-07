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

#include "Racecar.h"
#include "Utilities.h"

namespace sdds {

   Racecar::Racecar(std::istream& is) : Car(is) {

      // get and validate booster (used to determine topspeed of a racecar)
      std::string line{};
      std::getline(is, line, '\n');
      eraseWhiteSpace(line);
      try {
         m_booster = std::stod(line);
      }
      catch (...) {
         throw(std::string("Invalid record!"));
      }
   }

   void Racecar::display(std::ostream& os) const {
      Car::display(os);
      os << "*";
   }

   double Racecar::topSpeed() const {
      return Car::topSpeed() + (Car::topSpeed() * m_booster);
   }

}
