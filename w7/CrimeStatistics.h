
#ifndef CRIME_STATISTICS_H_
#define CRIME_STATISTICS_H_

#include <iostream>
#include <string>

namespace sdds {

   struct Crime {
      std::string province;
      std::string district;
      std::string crime;
      size_t noCases;
      unsigned int year;
      size_t noResolved;
   };

   class CrimeStatistics {
      Crime* m_crime{};

   public:
      CrimeStatistics(const char*);
      void display(std::ostream& out) const;

   };
}

#endif // CRIME_STATISTICS_H_
