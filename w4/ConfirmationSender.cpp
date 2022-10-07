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

   ConfirmationSender::ConfirmationSender() {}

   ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
      this->operator=(cs);
   }

   ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) {
      if (this != &cs) {
         m_size = cs.m_size;
         m_res = cs.m_res;
      }
      return *this;
   }

   ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) {
      *this = std::move(cs);
   }

   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) {
      if (this != &cs) {
         m_size = cs.m_size;
         m_res = cs.m_res;
         cs.m_size = 0;
         cs.m_res = nullptr;
      }
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
      // validate reservation
      ConfirmationSender temp;
      bool match{false};
      if (m_size) {
         for (unsigned i{ 0 }; i < m_size && !match; i++) {
            if (m_res[i] == &res) {
               match = true;
            }
         }
      }
      if (!match) {
         m_size++;
         temp.m_res = new const Reservation * [m_size];
         for (unsigned i{ 0 }; i < m_size - 1; i++) {
            temp.m_res[i] = m_res[i];
            m_res[i] = nullptr;
         }
         temp.m_res[m_size - 1] = &res;
         delete[] m_res;
         m_res = temp.m_res;
      }
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      ConfirmationSender temp;
      bool match{ false };
      if (m_size) {
         for (unsigned i{ 0 }; i < m_size && !match; i++) {
            if (m_res[i] == &res) {
               match = true;
               m_res[i] = nullptr;
               for (++i; i < m_size; i++) {
                  m_res[i - 1] = m_res[i];
               }
            }
         }
      }
      if (match) {
         //for (unsigned i{ 0 }; i < m_size; i++) { delete m_res[i]; m_res[i] = nullptr; };
         //delete [] m_res;
         m_size--;
         temp.m_res = new const Reservation * [m_size];
         for (unsigned i{ 0 }; i < m_size; i++) {
            temp.m_res[i] = m_res[i];
            m_res[i] = nullptr;
         }
         delete[]m_res;
         m_res = temp.m_res;
      }
      return *this;
   }

   ConfirmationSender::~ConfirmationSender() {
      m_res = nullptr;
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
         for (unsigned i{ 0 }; i < res.m_size; i++) {
            os << *res.m_res[i];
         }
      }
      os << "--------------------------" << std::endl;
      return os;
   }
}
