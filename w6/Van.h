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

#ifndef VAN_H_
#define VAN_H_

#include <string>

#include "Vehicle.h"

namespace sdds {

   class Van: public Vehicle
   {
      std::string m_maker{};

      enum Type {
         pickup, minibus, camper
      };

      Type m_type{};

      enum State {
         newVan, usedVan, brokenVan
      };

      State m_state{};

      enum Usage {
         delivery, passenger, camping
      };

      Usage m_usage{};

      double m_topSpeed{};

   public:

      // reads from input stream to construct a van
      Van(std::istream&);

      // returns top speed
      virtual double topSpeed() const;

      // displays a van to output stream
      virtual void display(std::ostream&) const;

      // returns condition of van
      virtual std::string condition() const;

      // returns type of van
      virtual std::string type() const;

      // returns purpose of van
      virtual std::string usage() const;
   };

}

#endif // VAN_H_

