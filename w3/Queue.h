
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
      static T dummy;

   public:

      Queue();
      bool push(const T& item);
      T& pop();
      size_t size() const;
      void display(std::ostream& os = std::cout);
      T operator[](unsigned int index);

   };

   /******************** TEMPLATE DEFINITIONS ********************/

   template<typename T, size_t CAPACITY>
   T Queue<T, CAPACITY>::dummy;

   template <typename T, size_t CAPACITY>
   Queue<T, CAPACITY>::Queue() {}

   template <typename T, size_t CAPACITY>
   bool Queue<T, CAPACITY>::push(const T& item) {
      T copy = item;
      if (m_size < CAPACITY) {
         m_queue[m_size++] = copy;
         return true;
      }
      else return false;
   }

   template <typename T, size_t CAPACITY>
   T& Queue<T, CAPACITY>::pop() {
      Queue<T, CAPACITY> temp = m_queue[0];
      for (int i = 1; i < m_size - 1; i++) {
         m_queue[i] = m_queue[i + 1];
      }
      return temp;
   }

   template <typename T, size_t CAPACITY>
   size_t Queue<T, CAPACITY>::size() const {
      return m_size;
   }

   template <typename T, size_t CAPACITY>
   void Queue<T, CAPACITY>::display(std::ostream& os) {
      os << std::setfill('*');
      os << std::setw(22) << "*" << std::endl;
      os << "| " << "Dictionary Content" << " |" << std::endl;
      os << std::setw(22) << "*" << std::endl;
      os << std::setfill(' ');
      for (int i = 0; i < m_size; i++) {
         os << (*this)[i] << std::endl;
      }
      os << "----------------------" << std::endl;
   }

   template <typename T, size_t CAPACITY>
   T Queue<T, CAPACITY>::operator[](unsigned int index) {
      return (index < m_size) ? m_queue[index] : dummy;
   }

   template<typename T, size_t CAPACITY>
   std::ostream& operator<<(std::ostream& os, const Queue<T, CAPACITY> queue) {
      os << T.display();
      return os;
   }

   /******************** SPECIALIZATIONS ********************/

   template<>
   Dictionary Queue<Dictionary, 100u>::dummy = {"Empty Term", "Empty Substitute"};


}



#endif // QUEUE_H_

