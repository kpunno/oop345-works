/*
==============
= WORKSHOP 6 =
==============

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

#ifndef LUXURYVAN_H_
#define LUXURYVAN_H_

#include "Van.h"

namespace sdds {

   class Luxuryvan : public Van {

      std::string m_consumption;

   public:

      // reads from a file to construct a luxuryvan
      Luxuryvan(std::istream&);

      //  displays a luxuryvan
      void display(std::ostream&) const;

      // returns m_consumption of the luxuryvan
      std::string consumption() const;

   };

}

#endif // LUXURYVAN_H_

