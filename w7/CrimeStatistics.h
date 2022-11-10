
#ifndef CRIME_STATISTICS_H_
#define CRIME_STATISTICS_H_

#include <vector>
#include <iostream>
#include <string>

namespace sdds {

   struct Crime {
      std::string m_province;
      std::string m_district;
      std::string m_crime;
      unsigned int m_year;
      size_t m_noCases;
      size_t m_noResolved;
   };

   class CrimeStatistics {
      std::vector<Crime> m_crimes{};

   public:
      // construct accepts filename and supplies m_crimes with a collection of crimes
      CrimeStatistics(const char*);

      // iterates through the collection, inserting each crime into ostream
      auto display(std::ostream& out)->void const;
   };

   // splices a string, returning the substring, and erasing the extracted content from line
   std::string splice(std::string&, size_t);

   // trims trailing and leading whitespace
   auto eraseWhiteSpace(std::string&)->void;

   // inserts a crime into ostream
   auto operator<<(std::ostream& out, const Crime& crime)->std::ostream&;
}

#endif // CRIME_STATISTICS_H_
