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

#ifndef UNQ_QUEUE_H_
#define UNQ_QUEUE_H_

#include "Queue.h"

namespace sdds {

   template<typename T>
   class UniqueQueue : public Queue<T, 100> {

   public:
      UniqueQueue() {}

      bool push(const T& item) override;

      ~UniqueQueue() {}
   };
   
   // push override ensures that a duplicate item will not be added to the queue of unique elements
   template <typename T>
   bool UniqueQueue<T>::push(const T& item) {
      bool unique = true;
      for (unsigned int i = 0; i < this->size() && (unique); i++) {
         if ((*this)[i] == item) {
            unique = false;
         }
      }
      if (unique) {
         Queue<T, 100>::push(item);
      }
      return unique;
   }

   // a specialized push for doubles in a unique queue
   // checks a matching element within a range; (item + 0.005) >= m_queue[index] >= (item - 0.005)
   template<>
   bool UniqueQueue<double>::push(const double& item) {
      bool unique = true;
      double range = 0.005;
      for (unsigned int i = 0; i < this->size() && unique; i++) {
         if (std::fabs((*this)[i]) <= (item + range) && std::fabs((*this)[i]) >= (item - range)) {
            unique = false;
         }
      }
      if (unique) {
         Queue::push(item);
      }
      return unique;
   }

   

}

#endif // UNQ_QUEUE_H_
