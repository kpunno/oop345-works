/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-10-09
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
      char m_id[ID_MAX]{};
      std::string m_name{};
      std::string m_email{};
      unsigned int m_partySize{};
      unsigned int m_day{};
      unsigned int m_hour{};

   public:
      Reservation();

      // updates day and/or time in the current reservation
      void update(int day, int time);

      // splits the string by delimiters to initialize object
      Reservation(const std::string& res);

      friend std::ostream& operator<<(std::ostream& os, const Reservation);
   };

   
}

#endif // RESERVATION_H_

