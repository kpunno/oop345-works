#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "Vehicle.h"

namespace sdds {

   Vehicle* createInstance(std::istream&);

   void eraseWhiteSpace(std::string&);

}

#endif // UTILITIES_H_

