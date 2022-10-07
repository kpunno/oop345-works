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
#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {

   Restaurant::Restaurant() {}

   Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
      m_res = new Reservation * [cnt];
      for (unsigned int i = 0; i < cnt; i++) {
         m_res[i] = new Reservation;
         *m_res[i] = *reservations[i];
      }
      m_size = cnt;
   }

   Restaurant::Restaurant(const Restaurant& resto) {
      this->operator=(resto);
   }

   Restaurant& Restaurant::operator=(const Restaurant& resto) {
      if (this != &resto) {
         while (m_size) {
            delete m_res[--m_size];
         }
         delete[] m_res;
         m_size = resto.m_size;
         m_res = new Reservation * [m_size];
         for (unsigned int i = 0; i < m_size; i++) {
            m_res[i] = new Reservation;
            *m_res[i] = *resto.m_res[i];
         }
      }
      return *this;
   }

   Restaurant::Restaurant(Restaurant&& resto) {
      *this = std::move(resto);
   }

   Restaurant& Restaurant::operator=(Restaurant&& resto) {
      if (this != &resto) {
         while (m_size) {
            delete m_res[--m_size];
         }
         delete[] m_res;
         m_size = resto.m_size;
         m_res = resto.m_res;
         for (unsigned int i = 0; i < m_size; i++) {
            m_res[i] = resto.m_res[i];
         }
         resto.m_size = 0;
         resto.m_res = nullptr;
      }
      return *this;
   }
   Restaurant::~Restaurant() {
      while (m_size) {
         delete m_res[--m_size];
      }
      delete[] m_res;
      m_res = nullptr;
   }

   size_t Restaurant::size() {
      return m_size;
   }

   std::ostream& operator<<(std::ostream& os, const Restaurant& resto) {
      static unsigned int callCnt{};
      callCnt++;
      os << "--------------------------" << std::endl;
      os << "Fancy Restaurant (" << callCnt << ")" << std::endl;
      os << "--------------------------" << std::endl;
      if (resto.m_res != nullptr) {
         for (unsigned int i = 0; i < resto.m_size; i++) {
            os << *resto.m_res[i];
         }
      }
      else {
         os << "This restaurant is empty!" << std::endl;
      }
      os << "--------------------------" << std::endl;
      return os;
   }
}
