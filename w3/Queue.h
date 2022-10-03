
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

#ifndef QUEUE_H_
#define QUEUE_H_


#include <iostream>
#include <iomanip>
#include "Dictionary.h"

namespace sdds {

   // DO I NEED RULE OF 5?

   template <typename T, size_t CAPACITY>
   class Queue
   {
      T m_queue[CAPACITY]{};
      size_t m_size{};
      static T m_dummy;

   public:

      Queue() {}

      virtual bool push(const T& item) {
         T copy = item;
         if (m_size < CAPACITY) {
            m_queue[m_size++] = copy;
            return true;
         }
         else return false;
      }

      T pop() {
         T temp = m_queue[0];
         for (unsigned int i = 0; i < m_size - 1; i++) {
            m_queue[i] = m_queue[i + 1];
         }
         m_size--;
         return temp;
      }


      size_t size() const {
         return m_size;
      }

      void display(std::ostream& os = std::cout) {
         os << std::setfill('-');
         os << std::setw(22) << "-" << std::endl;
         os << "| " << "Dictionary Content" << " |" << std::endl;
         os << std::setw(22) << "-" << std::endl;
         os << std::setfill(' ');
         for (unsigned int i = 0; i < m_size; i++) {
            os << (*this)[i] << std::endl;
         }
         os << "----------------------" << std::endl;
      }

      T operator[](unsigned int index) {
         return (index < m_size) ? m_queue[index] : m_dummy;
      }

      virtual ~Queue() {}
   };

   template<typename T, size_t CAPACITY>
   T Queue<T, CAPACITY>::m_dummy;

   template<typename T, size_t CAPACITY>
   std::ostream& operator<<(std::ostream& os, const Queue<T, CAPACITY> queue) {
      os << Queue<T, CAPACITY>::T.display();
      return os;
   }

   template<>
   Dictionary Queue<Dictionary, 100u>::m_dummy = { "Empty Term", "Empty Substitute" };


}



#endif // QUEUE_H_

