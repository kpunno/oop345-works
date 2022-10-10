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
         delete[] m_res;
         m_res = new const Reservation * [m_size];
         for (unsigned i{ 0 }; i < m_size; i++) {
            m_res[i] = cs.m_res[i];
         }
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
      if (find(res) < 0) {
         const Reservation** temp{nullptr};
         m_size++;
         temp = new const Reservation * [m_size];
         for (unsigned i{ 0 }; i < m_size - 1; i++) {
            temp[i] = m_res[i];
            m_res[i] = nullptr;
         }
         temp[m_size - 1] = &res;
         delete [] m_res;
         m_res = temp;
      }
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      int idx = find(res);
      if (idx >= 0) {
         shuffle(idx);
         const Reservation** temp{nullptr};
         m_size--;
         temp = new const Reservation * [m_size];
         for (unsigned i{ 0 }; i < m_size; i++) {
            temp[i] = m_res[i];
            m_res[i] = nullptr;
         }
         delete[]m_res;
         m_res = temp;
      }
      return *this;
   }

   int ConfirmationSender::find(const Reservation& res) const {
      int output{ -1 };
      bool match{ false };
      if (m_size) {
         for (unsigned i{ 0 }; i < m_size && !match; i++) {
            if (m_res[i] == &res) {
               match = true;
               output = i;
            }
         }
      }
      return output;
   }

   void ConfirmationSender::shuffle(unsigned idx) {
      m_res[idx] = nullptr;
      for (unsigned i = idx + 1; i < m_size; i++) {
         m_res[i - 1] = m_res[i];
      }
   }

   ConfirmationSender::~ConfirmationSender() {
      delete[] m_res;
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
