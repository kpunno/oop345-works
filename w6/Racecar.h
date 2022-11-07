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

#ifndef RACECAR_H_
#define RACECAR_H_

#include "Car.h"

namespace sdds {

   class Racecar: public Car
   {
      double m_booster;

   public:

      // reads from input stream to construct a racecar
      Racecar(std::istream&);

      // displays a racecar
      void display(std::ostream&) const;

      // returns m_topSpeed
      double topSpeed() const;

   };

}

#endif // RACECAR_H_

