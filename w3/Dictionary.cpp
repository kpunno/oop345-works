
/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-09-21
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Dictionary.h"

namespace sdds {

   Dictionary::Dictionary() {}

   std::ostream& Dictionary::display(std::ostream& os) {
      return os << std::setw(20) << getTerm() << ": " << getDefinition();
   }

   bool Dictionary::operator==(const Dictionary& rhs) {
      return m_term.compare(rhs.getTerm()) == 0 ? true : false;
   }
   
   std::ostream& operator<<(std::ostream& os, Dictionary dic) {
      dic.display();
      return os;
   }

}
