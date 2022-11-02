#ifndef AUTOSHOP_H_
#define AUTOSHOP_H_

#include <vector>
#include "Vehicle.h"

namespace sdds {

   class Autoshop
   {
      std::vector<Vehicle*> m_vehicles{};

   public:
      Autoshop& operator +=(Vehicle*);

      void display(std::ostream&) const;
   };

}

#endif // AUTOSHOP_H_

