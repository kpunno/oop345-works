/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-09-21
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

#include <iostream>
#include "Reservation.h"

namespace sdds {

   Reservation::Reservation() {

   }

   void Reservation::update(int day, int time) {

   }

   Reservation::Reservation(const std::string& res) {
      std::string temp = res;
      size_t pos;
      pos = res.find(":");
      temp.erase(pos);
      while (temp.npos != temp.find(" ")) {
         temp.erase(temp.find(" "), 1);
      }
      std::cout << temp << std::endl;
      std::cout << "*******************************************************" << std::endl;
   }

   std::ostream& operator<<(std::ostream& os, const Reservation reservation) {

      return os;
   }
}
