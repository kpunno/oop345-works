
#ifndef QUEUE_H_
#define QUEUE_H_


#include <iostream>
#include <iomanip>

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
      Queue(const Queue&);
      Queue& operator=(const Queue&);
      Queue(const Queue&&);
      Queue& operator=(const Queue&&);
      virtual ~Queue();


      bool push(const T& item);
      T& pop();
      size_t size() const;
      void display(std::ostream& os = std::cout);
      T operator[](int index);

   };

   template <typename T, size_t CAPACITY>
   Queue<T, CAPACITY>::Queue() { dummy = 0; }

   template <typename T, size_t CAPACITY>
   Queue<T, CAPACITY>::Queue(const Queue<T, CAPACITY>& queue) {
      operator=(queue);
   }

   template <typename T, size_t CAPACITY>
   Queue<T, CAPACITY>& Queue<T, CAPACITY>::operator=(const Queue<T, CAPACITY>& queue) {
      if (this != &queue) {
         dummy = queue.dummy;
         m_size = queue.m_size;
      }
      // what else needs to be done?
   }

   template <typename T, size_t CAPACITY>
   Queue<T, CAPACITY>::Queue(const Queue<T, CAPACITY>&& queue) {
      *this = std::move(queue);
   }

   template <typename T, size_t CAPACITY>
   Queue<T, CAPACITY>& Queue<T, CAPACITY>::operator=(const Queue<T, CAPACITY>&& queue) {
      if (this != &queue) {
         dummy = queue.dummy;
         m_size = queue.m_size;
      }
      // what else needs to be done?
   }

   template <typename T, size_t CAPACITY>
   Queue<T, CAPACITY>::~Queue() {}

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
         os << m_queue[i] << std::endl;
      }
   }

   template <typename T, size_t CAPACITY>
   T Queue<T, CAPACITY>::operator[](int index) {
      return (index < m_size && index >= 0) ? m_queue[index] : dummy;
   }

   template<typename T, size_t CAPACITY>
   std::ostream& operator<<(std::ostream& os, const Queue<T, CAPACITY> queue) {
      return os;
   }

   template<>

}



#endif // QUEUE_H_

