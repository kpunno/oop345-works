/*
==============
= WORKSHOP 6 =
==============

Name----Kristjan Punno
Email-- - kpunno@myseneca.ca
ID------ 150695211
Section - NCC
Date---- 2022 - 11 - 06
+ ---------------------------------------------------------------------- +
| I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments. |
+---------------------------------------------------------------------- +
*/

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
