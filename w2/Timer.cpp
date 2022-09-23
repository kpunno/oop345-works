
#include <iostream>
#include <chrono>
#include "Timer.h"


namespace sdds {
   using namespace std::chrono;

   void Timer::start() {
      startTime = steady_clock::now();
   }

   int Timer::stop() {
      steady_clock::time_point endTime = steady_clock::now();
      auto ns = duration_cast<nanoseconds>(endTime - startTime).count();
      return ns;
   }

}
