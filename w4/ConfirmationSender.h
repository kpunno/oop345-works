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


#ifndef CONFIRMATION_SENDER_H_
#define CONFIRMATION_SENDER_H_

#include "Reservation.h"

namespace sdds {
   class ConfirmationSender
   {
      const Reservation** m_res{};
      size_t m_size{};

   public:
 
      ConfirmationSender();

      ConfirmationSender(const ConfirmationSender&);

      ConfirmationSender& operator=(const ConfirmationSender&);

      ConfirmationSender(ConfirmationSender&&);

      ConfirmationSender& operator=(ConfirmationSender&&);

      virtual ~ConfirmationSender();

      // add to array
      ConfirmationSender& operator+=(const Reservation& res);
      
      // delete from array
      ConfirmationSender& operator-=(const Reservation& res);

      // searches array for supplied reservation
      int find(const Reservation& res) const;

      // used in operator-= ... 
      // if find is successful, nullifies the index, shuffles each successive index back a position
      void shuffle(unsigned idx);

      // ostream operator overload
      friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
   };
}

#endif //CONFIRMATION_SENDER_H_

