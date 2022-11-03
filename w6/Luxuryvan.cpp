
#include <iostream>
#include "Luxuryvan.h"

namespace sdds {

   Luxuryvan::Luxuryvan(std::istream& is) : Van(is) {

   }

   void Luxuryvan::display(std::ostream& os) const {

   }

   std::string Luxuryvan::consumption() const {
      return m_consumption;
   }

}
