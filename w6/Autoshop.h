#ifndef AUTOSHOP_H_
#define AUTOSHOP_H_

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {

   class Autoshop
   {
      std::vector<Vehicle*> m_vehicles{};

   public:
      Autoshop& operator +=(Vehicle*);

      void display(std::ostream&) const;

      template <typename T>
      void select(T test, std::list<const Vehicle*>& vehicles) {

      }

      virtual ~Autoshop();
   };

}

#endif // AUTOSHOP_H_

