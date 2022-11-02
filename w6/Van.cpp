

#include <iostream>
#include <iomanip>
#include "Van.h"
#include "Utilities.h"

namespace sdds {

   Van::Van(std::istream& is) {

      std::string line{};
      std::getline(is, line, ',');
      eraseWhiteSpace(line);
      m_maker = line;

      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'p' || line[0] == 'P')
         m_type = pickup;

      else if (line[0] == 'm' || line[0] == 'M')
         m_type = minibus;

      else if (line[0] == 'c' || line[0] == 'C')
         m_type = camper;

      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'd' || line[0] == 'D')
         m_usage = delivery;

      else if (line[0] == 'p' || line[0] == 'P')
         m_usage = passenger;

      else if (line[0] == 'c' || line[0] == 'C')
         m_usage = camping;

      std::getline(is, line, ',');
      eraseWhiteSpace(line);

      if (line[0] == 'n')
         m_state = newVan;

      else if (line[0] == 'u')
         m_state = usedVan;

      else if (line[0] == 'b')
         m_state = brokenVan;

      std::getline(is, line, '\n');
      eraseWhiteSpace(line);
      m_topSpeed = std::stod(line);
   }

   double Van::topSpeed() const {
      return m_topSpeed;
   }

   void Van::display(std::ostream& os) const {

      os << "| ";
      os << std::right;
      os << std::setw(8) << m_maker << " | ";
      os << std::left;
      os << std::setw(12) << type() << " | ";
      os << std::setw(12) << usage() << " | ";
      os << std::setw(6) << condition() << " | ";
      os << std::fixed << std::setprecision(2);
      os << std::setw(6) << m_topSpeed << " |";
      os << std::endl;

   }

   std::string Van::condition() const {
      switch (m_state) {

      case 0: return "new";

      case 1: return "used";

      case 2: return "broken";

      default: throw "Invalid van state";
      }
   }

   std::string Van::type() const {
      switch (m_state) {

      case 0: return "pickup";

      case 1: return "minibus";

      case 2: return "camper";

      default: throw "Invalid van type";
      }
   }

   std::string Van::usage() const {
      switch (m_state) {

      case 0: return "delivery";

      case 1: return "passenger";

      case 2: return "camping";

      default: throw "Invalid van usage case";
      }
   }
}
