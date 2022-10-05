/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-10-03
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/


#include <string>

namespace sdds {
   class Utils
   {
   public:
      // updates the position 
      static size_t findNewPos(std::string& str, size_t pos, char delim);
      static void eraseWhiteSpace(std::string& str);
      inline static bool debug = false;

      // maybe delete
      static std::string& extractNext(size_t, std::string&);
   };
}

