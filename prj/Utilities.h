// Name: Kristjan Punno
// Seneca Student ID: 150695211
// Seneca email: kpunno@myseneca.ca
// Date of completion: 2022-12-01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>

namespace sdds {

   class Utilities {

      size_t m_widthField{ 1 };
      static char m_delimiter;

   public:

      // sets field width
      void setFieldWidth(size_t newWidth);

      size_t getFieldWidth() const;

      std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

      static void setDelimiter(char newDelimiter);

      static char getDelimiter();

      std::string& eraseWhiteSpace(std::string& str);
   };

}

#endif // !UTILITIES_H_
