
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

namespace sdds {

   // DO I NEED RULE OF 5?

   template <typename T, size_t capacity>
   class Queue
   {
      T* m_queue[capacity];
      size_t m_size{};
      T obj{};

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
      void display(const std::ostream& os = std::cout);
      Queue operator[](int index);

   };

   template <typename T, size_t capacity>
   Queue<T, capacity>::Queue() {}

   template <typename T, size_t capacity>
   Queue<T, capacity>::Queue(const Queue<T, capacity>& queue) {
      operator=(queue);
   }

   template <typename T, size_t capacity>
   Queue<T, capacity>& Queue<T, capacity>::operator=(const Queue<T, capacity>& queue) {
      if (this != &queue) {
         obj = queue.obj;
         m_size = queue.m_size;
      }
      // what else needs to be done?
   }

   template <typename T, size_t capacity>
   Queue<T, capacity>::Queue(const Queue<T, capacity>&& queue) {
      *this = std::move(queue);
   }

   template <typename T, size_t capacity>
   Queue<T, capacity>& Queue<T, capacity>::operator=(const Queue<T, capacity>&& queue) {
      if (this != &queue) {
         obj = queue.obj;
         m_size = queue.m_size;
      }
      // what else needs to be done?
   }

   template <typename T, size_t capacity>
   Queue<T, capacity>::~Queue() {

   }

   template <typename T, size_t capacity>
   bool Queue<T, capacity>::push(const T& item) {
      if (m_size < (size_t)(capacity)) {
         m_queue[m_size] = item;
      }
   }

   template <typename T, size_t capacity>
   T& Queue<T, capacity>::pop() {
      Queue<T, capacity> temp = m_queue[0];
      for (int 0 = 1; i < m_size - 1; i++) 
         queue[i] = queue[i + 1];
   }

   template <typename T, size_t capacity>
   size_t Queue<T, capacity>::size() const {
      return m_size;
   }

   template <typename T, size_t capacity>
   void Queue<T, capacity>::display(const std::ostream& os) {

   }

   template <typename T, size_t capacity>
   Queue<T, capacity> Queue<T, capacity>::operator[](int index) {

   }
}




#endif // QUEUE_H_

