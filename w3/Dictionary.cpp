#include <iostream>
#include <iomanip>
#include "Dictionary.h"

namespace sdds {

   Dictionary::Dictionary() {}

   /*Dictionary::Dictionary(const Dictionary&) {

   }
   Dictionary& Dictionary::operator=(const Dictionary&) {

   }
   Dictionary::Dictionary(const Dictionary&&) {

   }
   Dictionary& Dictionary::operator=(const Dictionary&&) {

   }
   Dictionary::~Dictionary() {}*/
   
   std::ostream& operator<<(std::ostream& os, Dictionary dic) {
      os << std::setw(20) << dic.getTerm() << ": " << dic.getDefinition();
      return os;
   }

}
