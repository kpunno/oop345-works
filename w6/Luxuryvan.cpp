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

#include "Luxuryvan.h"
#include "Utilities.h"

namespace sdds {

   Luxuryvan::Luxuryvan(std::istream& is) : Van(is) {

      // get and validate consumption type
      std::string line{};
      std::getline(is, line, '\n');
      eraseWhiteSpace(line);

      if (line[0] == 'e')
         m_consumption = "electric van  *";
      else if (line[0] == 'g')
         throw(std::string("Invalid record!"));
   }

   void Luxuryvan::display(std::ostream& os) const {
      Van::display(os);
      os << " " << m_consumption;
   }

   std::string Luxuryvan::consumption() const {
      return m_consumption;
   }

}
