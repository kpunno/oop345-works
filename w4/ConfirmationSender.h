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
      const Reservation** m_res{};
      size_t m_size{};

   public:
      // default constructor
      ConfirmationSender();

      // copy constructor
      ConfirmationSender(const ConfirmationSender&);

      // copy assign
      ConfirmationSender& operator=(const ConfirmationSender&);

      // move constructor
      ConfirmationSender(ConfirmationSender&&);

      // move assign
      ConfirmationSender& operator=(ConfirmationSender&&);

      // destructor
      virtual ~ConfirmationSender();

      // returns size -- NECESSARY************ ??
      size_t size();

      // add to array
      ConfirmationSender& operator+=(const Reservation& res);
      
      // delete from array
      ConfirmationSender& operator-=(const Reservation& res);

      // ostream operator overload
      friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
   };
}

#endif //CONFIRMATION_SENDER_H_

