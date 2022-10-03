
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

   size_t Utils::findNewPos(std::string& str, size_t pos, char delim) {
      str.erase(0, pos);
      pos = str.find(delim);
      return pos;
   }
}
