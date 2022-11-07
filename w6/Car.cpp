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

#include <iostream>
#include <iomanip>
#include <string>

#include "Car.h"
#include "Utilities.h"

namespace sdds {



   Car::Car(std::istream& is) {

      std::string line{};

      // ignore type
      std::getline(is, line, ',');

      // get m_maker
      std::getline(is, line, ',');
      eraseWhiteSpace(line);
      m_maker = line;

      // get and validate car condition
      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'n' || line[0] == 'N' || line == "")
         m_state = newCar;

      else if (line[0] == 'u' || line[0] == 'U')
         m_state = usedCar;

      else if (line[0] == 'b' || line[0] == 'B')
         m_state = brokenCar;

      else {
         is.ignore(1000, '\n');
         throw(std::string("Invalid record!"));
      }

      // get and validate top speed
      getline(is, line, ',');
      eraseWhiteSpace(line);
      try {
         m_topSpeed = std::stod(line);
      }
      catch (...) {
         throw(std::string("Invalid record!"));
      }
      
   }

   double Car::topSpeed() const {
      return m_topSpeed;
   }

   void Car::display(std::ostream& os) const {
      os << "| ";
      os << std::right;
      os << std::setw(10) << m_maker << " | ";
      os << std::left;
      os << std::setw(6) << condition() << " | ";
      os << std::fixed << std::setprecision(2);
      os << std::setw(6) << topSpeed() << " |";
   }

   std::string Car::condition() const {
      switch (m_state) {

         case 0: return "new";

         case 1: return "used";

         case 2: return "broken";

         default: throw "Invalid car condition";
      }
   }
}
