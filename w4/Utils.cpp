
#include <string>
#include "Utils.h"

namespace sdds {
   void Utils::eraseWhiteSpace(std::string& str) {
      unsigned int i = 0;
      while (str[i] == ' ') {
         str.erase(i, 1);
      }
      i = str.length() - 1;
      while (str[i] == ' ') {
         str.erase(i--, 1);
      }
      
   }
}
