#include <iostream>
#include <iomanip>
#include "Dictionary.h"

namespace sdds {

   Dictionary::Dictionary() {}

   std::ostream& Dictionary::display(std::ostream& os) {
      return os << std::setw(20) << getTerm() << ": " << getDefinition();
   }
   
   std::ostream& operator<<(std::ostream& os, Dictionary dic) {
      dic.display();
      return os;
   }

}
