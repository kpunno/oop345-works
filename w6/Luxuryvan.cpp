
#include <iostream>
#include "Luxuryvan.h"
#include "Utilities.h"

namespace sdds {

   Luxuryvan::Luxuryvan(std::istream& is) : Van(is) {
      std::string line{};
      std::getline(is, line, '\n');
      eraseWhiteSpace(line);
      if (line[0] == 'e' || line[0] == 'g')
         m_consumption = "electric van *";
   }

   void Luxuryvan::display(std::ostream& os) const {
      Van::display(os);
      os << " " << m_consumption;
   }

   std::string Luxuryvan::consumption() const {
      return m_consumption;
   }

}
