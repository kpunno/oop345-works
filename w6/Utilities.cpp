
#include <string>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"

namespace sdds {

   Vehicle* createInstance(std::istream& is) {

      Vehicle* vehicle = nullptr;

      if (is.peek() != -1) {
         unsigned pos{};
         std::string line{};

         std::getline(is, line, '\n');
         std::istringstream sstream(line);
         eraseWhiteSpace(line);

         if (line[0] == 'c' || line[0] == 'C')
            vehicle = new Car(sstream);

         else if (line[0] == 'v' || line[0] == 'V')
            vehicle = new Van(sstream);

         else if (line[0] == 'r' || line[0] == 'R')
            vehicle = new Racecar(sstream);

         else if (line[0] == 'l' || line[0] == 'L')
            vehicle = new Luxuryvan(sstream);

         else {
            vehicle = nullptr;
            line = line[0];
            throw(std::string("Unrecognized record type [" + line + "]"));
         }
      }

      return vehicle;

   }

   void eraseWhiteSpace(std::string& str) {
      unsigned int i = 0;
      if (str != "") {
         while (str[i] == ' ') {
            str.erase(i, 1);
         }
         if (str.length() != 0) {
            i = str.length() - 1;
            while (str[i] == ' ') {
               str.erase(i--, 1);
            }
         }
      }
   }


}
