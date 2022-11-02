
#include <iostream>
#include <iomanip>
#include <string>

#include "Car.h"
#include "Utilities.h"

namespace sdds {



   Car::Car(std::istream& is) {
      std::string line{};

      std::getline(is, line, ',');
      eraseWhiteSpace(line);
      m_maker = line;

      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'n')
         m_state = newCar;

      else if (line[0] == 'u')
         m_state = usedCar;

      else if (line[0] == 'b')
         m_state = brokenCar;

      std::getline(is, line, '\n');
      eraseWhiteSpace(line);
      m_topSpeed = std::stod(line);
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
      os << std::setw(6) << m_topSpeed << " |";
      os << std::endl;

   }

   std::string Car::condition() const {
      switch (m_state) {

         case 0: return "new";

         case 1: return "used";

         case 2: return "broken";

         default: return "unknown state";
      }
   }
}
