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

      // reads from input stream to construct a car
      Car(std::istream&);

      // returns m_topSpeed
      virtual double topSpeed() const;

      // displays a car
      virtual void display(std::ostream&) const;

      // returns the condition of the car
      virtual std::string condition() const;
   };
}

#endif // CAR_H_

