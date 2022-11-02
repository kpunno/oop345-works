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

      Type m_typeP{};

      enum State {
         newVan, usedVan, brokenVan
      };

      State m_state{};

      enum Purpose {
         delivery, passenger, camping
      };

      Purpose m_purpose{};

      double topSpeed{};

   public:

      Van(std::istream&);


   };

}

#endif // VAN_H_

