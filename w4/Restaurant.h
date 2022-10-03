/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-10-03
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/


#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <iostream>
#include "Reservation.h"

namespace sdds {
   class Restaurant
   {
      Reservation** res;
      size_t m_size;
   public:
      Restaurant();
      Restaurant(const Reservation* reservations[], size_t cnt);
      Restaurant(const Restaurant& resto);
      Restaurant& operator=(const Restaurant& resto);
      Restaurant(Restaurant&& resto);
      Restaurant& operator=(Restaurant&& resto);

      virtual ~Restaurant();
      size_t size();

      friend std::ostream& operator<<(std::ostream& os, const Restaurant& resto);
   };
}

#endif //RESTAURANT_H_

