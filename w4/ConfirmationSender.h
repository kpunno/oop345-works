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


#ifndef CONFIRMATION_SENDER_H_
#define CONFIRMATION_SENDER_H_

#include "Reservation.h"

namespace sdds {
   class ConfirmationSender
   {
      const Reservation** res;
   public:
      ConfirmationSender& operator+=(const Reservation& res);
      ConfirmationSender& operator-=(const Reservation& res);

      friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
   };
}

#endif //CONFIRMATION_SENDER_H_

