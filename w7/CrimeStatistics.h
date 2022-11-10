
#ifndef CRIME_STATISTICS_H_
#define CRIME_STATISTICS_H_

#include <vector>
#include <list>
#include <iostream>
#include <string>

namespace sdds {

   struct Crime {
      std::string m_province;
      std::string m_district;
      std::string m_crime;
      unsigned int m_year;
      size_t m_cases;
      size_t m_resolved;
   };

   class CrimeStatistics {
      std::vector<Crime> m_crimes{};

   public:
      // construct accepts filename and supplies m_crimes with a collection of crimes
      CrimeStatistics(const char*);

      // iterates through the collection, inserting each crime into ostream
      auto display(std::ostream& out)->void const;

      // sorts crimes based on supplied parameter
      void sort(const char*);

      // updates [none] in crimes to a new thing
      void cleanList();

      // returns true if in collection
      bool inCollection(const char*) const;

      // receives list for a province
      std::list<Crime> getListForProvince(const char*) const;
      
   };



   // *** HELPERS *** //

   // splices a string, returning the substring, and erasing the extracted content from line
   std::string splice(std::string&, size_t);

   // trims trailing and leading whitespace
   auto eraseWhiteSpace(std::string&)->void;

   // inserts a crime into ostream
   auto operator<<(std::ostream& out, const Crime& crime)->std::ostream&;
}

#endif // CRIME_STATISTICS_H_
