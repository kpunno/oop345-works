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

   template<typename T>
   class UniqueQueue : public Queue<T, 100u> {

      template <typename T, 100u>
      bool push(const T& item) override {
         T copy = item;
         bool unique = true;
         if (m_size < CAPACITY) {
            for (int i = 0; i < m_size && !flag; i++) {
               if ((*this)[i] == item) {
                  unique = false;
               }
            }
            if (unique) m_queue[m_size++] = copy;
         }
         return unique;
      }

      
   };

}
