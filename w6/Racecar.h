#ifndef RACECAR_H_
#define RACECAR_H_

#include "Car.h"

namespace sdds {

   class Racecar: public Car
   {
      double m_booster;

   public:

      Racecar(std::istream&);
      void display(std::ostream&) const;
      double topSpeed() const;

   };

}

#endif // RACECAR_H_

