
#include <string>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"

namespace sdds {

   Vehicle* createInstance(std::istream& is) {
      std::string line{};
      std::getline(is, line, ',');
      eraseWhiteSpace(line);
      Vehicle* vehicle = nullptr;

      if (line[0] == 'c' || line[0] == 'C')
         vehicle = new Car(is);

      else if (line[0] == 'v' || line[0] == 'V')
         vehicle = new Van(is);

      else vehicle = nullptr;

      return vehicle;

   }

   void eraseWhiteSpace(std::string& str) {
      unsigned int i = 0;
      if (str != "") {
         while (str[i] == ' ') {
            str.erase(i, 1);
         }
         i = str.length() - 1;
         while (str[i] == ' ') {
            str.erase(i--, 1);
         }
      }
   }


}
