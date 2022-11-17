/*
-- WORKSHOP 6 --

Name----Kristjan Punno
Email-- - kpunno@myseneca.ca
ID------ 150695211
Section - NCC
Date---- 2022 - 11 - 06
+ ---------------------------------------------------------------------- +
| I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments. |
+---------------------------------------------------------------------- +
*/

#ifndef CRIME_STATISTICS_H_
#define CRIME_STATISTICS_H_

#include <vector>
#include <list>
#include <iostream>
#include <string>

namespace sdds {

   struct Crime {
      std::string m_province{};
      std::string m_district{};
      std::string m_crime{};
      unsigned m_year{};
      unsigned m_cases{};
      unsigned m_resolved{};
   };

   class CrimeStatistics {
      std::vector<Crime> m_crimes{};

   public:
      // construct accepts filename and supplies m_crimes with a collection of crimes
      CrimeStatistics(const char*);

      // iterates through the collection, inserting each crime into ostream
      void display(std::ostream& out) const;

      // sorts crimes based on supplied parameter
      void sort(const char*);

      // updates [none] in crimes to a new thing
      void cleanList();

      // returns true if in collection
      bool inCollection(const char*) const;

      // receives list for a province
      std::list<Crime> getListForProvince(const char*) const;

      // inserts a crime into ostream
      friend std::ostream& operator<<(std::ostream& out, const Crime& crime);
      
   };



   // *** HELPERS *** //

   // splices a string, returning the substring, and erasing the extracted content from line
   std::string splice(std::string&, size_t);

   // trims trailing and leading whitespace
   void eraseWhiteSpace(std::string&);
}

#endif // CRIME_STATISTICS_H_
