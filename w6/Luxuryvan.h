#ifndef LUXURYVAN_H_
#define LUXURYVAN_H_

#include "Van.h"

namespace sdds {

   class Luxuryvan : public Van {

      std::string m_consumption;

   public:

      Luxuryvan(std::istream&);

      void display(std::ostream&) const;

      std::string consumption() const;

   };

}

#endif // LUXURYVAN_H_

