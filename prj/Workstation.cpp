// Name: Kristjan Punno
// Seneca Student ID: 150695211
// Seneca email: kpunno@myseneca.ca
// Date of completion: 2022-12-01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include "Workstation.h"

namespace sdds {

   std::deque<CustomerOrder> g_pending{};
   std::deque<CustomerOrder> g_completed{};
   std::deque<CustomerOrder> g_incomplete{};

   Workstation::Workstation(const std::string& str) : Station(str) {}

   void Workstation::fill(std::ostream& os) {
      if (m_orders.size()) {
         m_orders.front().fillItem(*this, os);
      }
   }

   bool Workstation::attemptToMoveOrder() {
      bool result = false;
      if (m_orders.size()) {
         if (m_orders.front().isItemFilled(getItemName()) || !getQuantity()) {
            result = true;
            if (m_pNextStation) {
               *m_pNextStation += std::move(m_orders.front());
            }
            else {
               if (m_orders.front().isOrderFilled()) {
                  g_completed.push_back(std::move(m_orders.front()));
               }
               else {
                  g_incomplete.push_back(std::move(m_orders.front()));
               }
            }
            m_orders.pop_front();
         }
      }
      return result;
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
      os << (m_pNextStation != nullptr ? m_pNextStation->getItemName() : "End of Line");
      os << std::endl;
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }

}
