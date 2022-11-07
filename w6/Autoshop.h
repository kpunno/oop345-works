/*
==============
= WORKSHOP 6 =
==============

Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-11-06
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

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
      // add a vehicle to m_vehicles
      Autoshop& operator +=(Vehicle*);

      // display an all vehicles held in the autoshop
      void display(std::ostream&) const;

      // performs predefined a lambda upon the autoshop, returning a list of matching vehicles
      template <typename T>
      void select(T test, std::list<const Vehicle*>& vehicles) {
         for (auto it = m_vehicles.cbegin(); it != m_vehicles.cend(); ++it) {
            if (test(*it)) {
               vehicles.push_back(*it);
            }
            
         }
      }

      // destroys dynamic memory located at each address stored in the autoshop
      virtual ~Autoshop();
   };

}

#endif // AUTOSHOP_H_

