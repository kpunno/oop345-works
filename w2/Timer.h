
#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

namespace sdds {
   
   using namespace std::chrono;
   
   class Timer
   {
      steady_clock::time_point startTime;
   public:
      void start();
      int stop();
   };

}

#endif // TIMER_H_