
#include <string>

namespace sdds {
   class Utils
   {
   public:
      // updates the position 
      static size_t findNewPos(std::string& str, size_t pos, char delim);
      static void eraseWhiteSpace(std::string& str);
      inline static bool debug = false;
   };
}

