
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

      // default constructor
      Queue() {}

      // a method that pushes an item of type T to end of the queue
      virtual bool push(const T& item) {
         T copy = item;
         if (m_size < CAPACITY) {
            m_queue[m_size++] = copy;
            return true;
         }
         else return false;
      }

      // a method that pops an item from queue's first element, and shuffles each item back an index
      T pop() {
         T temp = m_queue[0];
         for (unsigned int i = 0; i < m_size - 1; i++) {
            m_queue[i] = m_queue[i + 1];
         }
         m_size--;
         return temp;
      }

      // returns current count of items in queue
      size_t size() const {
         return m_size;
      }

      // formatted display for primitive types
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

      // returns the request element of the queue at the given index
      T operator[](unsigned int index) {
         return (index < m_size) ? m_queue[index] : m_dummy;
      }

      // default destructor
      virtual ~Queue() {}
   };

   // insantiates an empty m_dummy if the type is not user-defined
   template<typename T, size_t CAPACITY>
   T Queue<T, CAPACITY>::m_dummy{};

   // aids in outputting display of primitive-types to ostream
   template<typename T, size_t CAPACITY>
   std::ostream& operator<<(std::ostream& os, const Queue<T, CAPACITY> queue) {
      os << Queue<T, CAPACITY>::T.display();
      return os;
   }

   // a specialized instantiation of m_dummy for when the class-type is Dictionary, and the capacity is 100
   template<>
   Dictionary Queue<Dictionary, 100u>::m_dummy = { "Empty Term", "Empty Substitute" };


}



#endif // QUEUE_H_

