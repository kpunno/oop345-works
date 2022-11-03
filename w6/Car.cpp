
#include <iostream>
#include <iomanip>
#include <string>

#include "Car.h"
#include "Utilities.h"

namespace sdds {



   Car::Car(std::istream& is) {

      std::string line{};
      char c{};

      std::getline(is, line, ',');
      eraseWhiteSpace(line);
      m_maker = line;

      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'n' || line[0] == 'N' || line == "")
         m_state = newCar;

      else if (line[0] == 'u' || line[0] == 'U')
         m_state = usedCar;

      else if (line[0] == 'b' || line[0] == 'B')
         m_state = brokenCar;

      else {
         is.ignore(1000, '\n');
         throw(std::string("Invalid record!"));
      }


      line = "";

      while (is.peek() != ',' && is.peek() != '\n' && is.peek() != -1) {
         c = is.get();
         line += c;
      }
      eraseWhiteSpace(line);
      
      m_topSpeed = std::stod(line);
      
      
      //ignore either delimiter be it ',' or '\n'
      is.get();
   }

   double Car::topSpeed() const {
      return m_topSpeed;
   }

   void Car::display(std::ostream& os) const {
      os << "| ";
      os << std::right;
      os << std::setw(10) << m_maker << " | ";
      os << std::left;
      os << std::setw(6) << condition() << " | ";
      os << std::fixed << std::setprecision(2);
      os << std::setw(6) << topSpeed() << " |";
   }

   std::string Car::condition() const {
      switch (m_state) {

         case 0: return "new";

         case 1: return "used";

         case 2: return "broken";

         default: throw "Invalid car condition";
      }
   }
}
