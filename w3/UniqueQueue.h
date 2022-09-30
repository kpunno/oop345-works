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

#include "Queue.h"

namespace sdds {

   template<typename T, size_t CAPACITY>
   class UniqueQueue : public Queue<T, CAPACITY> {

      template <typename T, size_t CAPACITY>
      bool Queue<T, CAPACITY>::push(const T& item) override {
         T copy = item;
         bool output = true;
         if (m_size < CAPACITY) {
            for (int i = 0; i < m_size; i++) {
               if ((*this)[i] == item) {
                  output = false;
               }
            }
            if output == true m_queue[m_size++] = copy;
            return true;
         }
      }

   };

}
