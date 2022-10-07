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

   ConfirmationSender::ConfirmationSender() {
      // do something ?
   }

   ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
      this->operator=(cs);
   }

   ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) {
      if (this != &cs) {
         m_size = cs.m_size;
         m_res = cs.m_res;
         for (unsigned int i = 0; i < m_size; i++) {
            m_res[i] = cs.m_res[i];
         }
      }
      return *this;
   }

   ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) {
      //this->std::move(cs);
   }

   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) {
      return *this;
   }

   // returns size -- NECESSARY************ ??
   size_t size();

   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
      ConfirmationSender temp;
      // add something
      return temp;
   }

   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      ConfirmationSender temp;
      // substract something
      return temp;
   }

   ConfirmationSender::~ConfirmationSender() {
      // do something ?
   }


   std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res) {
      static unsigned int callCnt{};
      callCnt++;
      os << "--------------------------" << std::endl;
      os << "Confirmations to Send" << std::endl;
      os << "--------------------------" << std::endl;
      if (!res.m_size) {
         os << "There are no confirmations to send!" << std::endl;
      }
      else {
         // do something
      }
      os << "--------------------------" << std::endl;
      return os;
   }
}
