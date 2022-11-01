
#include <iostream>
#include <string>
#include "Car.h"

namespace sdds {

   void eraseWhiteSpace(std::string&);

   Car::Car(std::istream& is) {
      std::string line{};
      std::getline(is, line, ',');
      eraseWhiteSpace(line);
      if (line != "C" || line != "c") {

         std::getline(is, line, ',');
         eraseWhiteSpace(line);
         m_maker = line;

         std::getline(is, line, ',');
         eraseWhiteSpace(line);
         m_state = line[0];

         std::getline(is, line, ',');
         eraseWhiteSpace(line);
         m_topSpeed = std::stod(line);
      }
   }

   double Car::topSpeed() const {
      return m_topSpeed;
   }
   void Car::display(std::ostream& os) const {
      os << "hello";
   }
   std::string Car::condition() const {
      switch (m_state) {
         case 'N': return "new";
         case 'U': return "used";
         case 'B': return "broken";
         default : return "unknown state";
      }
   }

   void eraseWhiteSpace(std::string& str) {
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
