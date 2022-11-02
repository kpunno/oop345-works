

#include <iostream>
#include "Van.h"
#include "Utilities.h"

namespace sdds {

   Van::Van(std::istream& is) {

      // NEEDS REVISION FROM CAR (copy, paste)
      // SPECIFIC TO A VAN

      std::string line{};
      std::getline(is, line, ',');
      eraseWhiteSpace(line);



   }

}
