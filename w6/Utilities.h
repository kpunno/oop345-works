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

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "Vehicle.h"

namespace sdds {

   // creates an instance of a vehicle,
   // using input stream to determine which type of vehicle to create an instance of
   Vehicle* createInstance(std::istream&);

   // utility function to erase trailing and leading whitespace from supplied string
   void eraseWhiteSpace(std::string&);

}

#endif // UTILITIES_H_

