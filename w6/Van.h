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

      Van(std::istream&);

      virtual double topSpeed() const;
      virtual void display(std::ostream&) const;
      virtual std::string condition() const;
      virtual std::string type() const;
      virtual std::string usage() const;
   };

}

#endif // VAN_H_

