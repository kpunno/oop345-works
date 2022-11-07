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

#include "Van.h"
#include "Utilities.h"

namespace sdds {

   Van::Van(std::istream& is) {

      std::string line{};

      // ignore vehicle type string
      std::getline(is, line, ',');

      // gets van maker
      std::getline(is, line, ',');
      eraseWhiteSpace(line);
      m_maker = line;

      // gets and validates type of van
      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'p' || line[0] == 'P')
         m_type = pickup;

      else if (line[0] == 'm' || line[0] == 'M')
         m_type = minibus;

      else if (line[0] == 'c' || line[0] == 'C')
         m_type = camper;

      else {
         is.ignore(1000, '\n');
         throw(std::string("Invalid record!"));
      }


      // gets and validates usage of van
      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'd' || line[0] == 'D')
         m_usage = delivery;

      else if (line[0] == 'p' || line[0] == 'P')
         m_usage = passenger;

      else if (line[0] == 'c' || line[0] == 'C')
         m_usage = camping;

      else {
         is.ignore(1000, '\n');
         throw(std::string("Invalid record!"));
      }


      // gets and validates condition of van
      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'n' || line[0] == 'N' || line == "")
         m_state = newVan;

      else if (line[0] == 'u' || line[0] == 'U')
         m_state = usedVan;

      else if (line[0] == 'b' || line[0] == 'B')
         m_state = brokenVan;

      else {
         is.ignore(1000, '\n');
         throw(std::string("Invalid record!"));
      }

      // gets and validates top speed
      std::getline(is, line, ',');
      eraseWhiteSpace(line);
      try {
         m_topSpeed = std::stod(line);
      }
      catch (...) {
         throw(std::string("Invalid record!"));
      }
   }

   double Van::topSpeed() const {
      return m_topSpeed;
   }

   void Van::display(std::ostream& os) const {

      os << "| ";
      os << std::right;
      os << std::setw(8) << m_maker << " | ";
      os << std::left;
      os << std::setw(12) << type() << " | ";
      os << std::setw(12) << usage() << " | ";
      os << std::setw(6) << condition() << " | ";
      os << std::fixed << std::setprecision(2);
      os << std::setw(6) << m_topSpeed << " |";

   }

   std::string Van::condition() const {
      switch (m_state) {

      case 0: return "new";

      case 1: return "used";

      case 2: return "broken";

      default: throw "Invalid van state";
      }
   }

   std::string Van::type() const {
      switch (m_type) {

      case 0: return "pickup";

      case 1: return "mini-bus";

      case 2: return "camper";

      default: throw "Invalid van type";
      }
   }

   std::string Van::usage() const {
      switch (m_usage) {

      case 0: return "delivery";

      case 1: return "passenger";

      case 2: return "camping";

      default: throw "Invalid van usage case";
      }
   }
}
