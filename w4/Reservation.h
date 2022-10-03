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

//#include <iostream>
#include <string>

#ifndef RESERVATION_H_
#define RESERVATION_H_

constexpr int ID_MAX = 10 + 1;

namespace sdds {

   class Reservation
   {
      char id[ID_MAX]{};
      std::string name{};
      std::string email{};
      unsigned int partySize{};
      unsigned int day{};
      unsigned int hour{};

   public:
      Reservation();

      void update(int day, int time);

      Reservation(const std::string& res);

      friend std::ostream& operator<<(std::ostream& os, const Reservation reservation);
   };

   
}

#endif // RESERVATION_H_

