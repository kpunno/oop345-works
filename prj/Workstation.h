
#ifndef WORKSTATION_H_
#define WORKSTATION_H_

#include <queue>
#include <string>
#include <vector>
#include <deque>
#include "CustomerOrder.h"

namespace sdds {

   // GET ALL THE CONTENTS OF THE FILE
   // THEN -> REORDER THE FILE ACCORDING TO THE MATCHES
   // HINT: STARTS WITH BED

   static std::deque<CustomerOrder> g_pending{};
   static std::deque<CustomerOrder> g_completed{};
   static std::deque<CustomerOrder> g_incomplete{};

   class Workstation : public Station
   {

      std::deque<CustomerOrder> m_orders{};
      Workstation* m_pNextStation{};

   public:

      Workstation(const std::string& str);

      void fill(std::ostream&);

      bool attemptToMoveOrder();

      void setNextStation(Workstation* station);

      Workstation* getNextStation() const;

      void display(std::ostream& os) const;

      Workstation& operator+=(CustomerOrder&& newOrder);

   };

}

#endif // !WORKSTATION_H_