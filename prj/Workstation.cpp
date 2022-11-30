
#include <iostream>
#include <string>
#include "Workstation.h"

namespace sdds {

   

   Workstation::Workstation(const std::string& str) : Station(str) {}

   void Workstation::fill(std::ostream& os) {
      if (m_orders.size()) {
         
      }
   }

   bool Workstation::attemptToMoveOrder() {
      return false;
   }

   void Workstation::setNextStation(Workstation* station) {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const {
      os << getItemName();
      os << " --> ";
      os << (m_pNextStation ? m_pNextStation->getItemName() : "End of line");
      os << std::endl;
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      // temporary
      Workstation ws("hello");
      return ws;
   }

}
