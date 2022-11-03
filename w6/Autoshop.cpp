

#include "Autoshop.h"

namespace sdds {

   Autoshop& Autoshop::operator +=(Vehicle* vehicle) {
      m_vehicles.push_back(vehicle);

      return *this;
   }

   void Autoshop::display(std::ostream& os) const {
      
      for (auto it = m_vehicles.cbegin(); it != m_vehicles.cend(); ++it) {
         (*it)->display(os);
         os << std::endl;
      }
   }

   Autoshop::~Autoshop() {
      for (auto it = m_vehicles.cbegin(); it != m_vehicles.cend(); ++it) {
         delete *it;
      }
   }

}
