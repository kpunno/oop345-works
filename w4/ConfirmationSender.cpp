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

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {

   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
      ConfirmationSender temp;
      return temp;
   }

   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      ConfirmationSender temp;
      return temp;
   }

   std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res) {
      static unsigned int callCnt{};
      callCnt++;
      
      return os;
   }
}
