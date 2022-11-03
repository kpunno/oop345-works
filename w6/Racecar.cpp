

#include <string>
#include "Racecar.h"
#include "Utilities.h"

namespace sdds {

   Racecar::Racecar(std::istream& is) : Car(is) {
      std::string line{};
      std::getline(is, line, '\n');
      eraseWhiteSpace(line);
      m_booster = std::stod(line);
   }

   void Racecar::display(std::ostream& os) const {
      Car::display(os);
      os << "*";
   }

   double Racecar::topSpeed() const {
      return Car::topSpeed() + (Car::topSpeed() * m_booster);
   }

}
