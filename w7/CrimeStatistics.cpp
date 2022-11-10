
#include <iostream>
#include <fstream>
#include "CrimeStatistics.h"

namespace sdds {

   CrimeStatistics::CrimeStatistics(const char* filename) {
      std::ifstream file;
      file.open(filename);

      if (file.is_open()) {

      }
      
   }

   void CrimeStatistics::display(std::ostream& out) const {
      ;
   }

}
