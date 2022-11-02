#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
   class Car : public Vehicle
   {
      std::string m_maker{};
      double m_topSpeed{};
      
      enum State {
         newCar, usedCar, brokenCar
      };

      State m_state{};

   public:

      Car(std::istream&);

      virtual double topSpeed() const;
      virtual void display(std::ostream&) const;
      virtual std::string condition() const;
   };
}

#endif // CAR_H_

