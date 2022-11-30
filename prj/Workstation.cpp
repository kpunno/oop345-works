
#include <string>
#include "Workstation.h"

namespace sdds {

   

   Workstation::Workstation(const std::string& str) : Station(str) {

   }

   void Workstation::fill(std::ostream& os) {

   }

   bool Workstation::attemptToMoveOrder() {
      return false;
   }

   void Workstation::setNextStation(Workstation* station) {

   }

   Workstation* Workstation::getNextStation() const {
      // temporary
      Workstation ws("hello");
      return &ws;
   }

   void Workstation::display(std::ostream& os) const {

   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      // temporary
      Workstation ws("hello");
      return ws;
   }

}
