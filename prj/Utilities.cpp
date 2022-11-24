// Name: Kristjan Punno
// Seneca Student ID: 150695211
// Seneca email: kpunno@myseneca.ca
// Date of completion: 2022-11-23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Utilities.h"

namespace sdds {

   char Utilities::m_delimiter{};

   void Utilities::setFieldWidth(size_t newWidth) {
      m_widthField = newWidth;
   }

   size_t Utilities::getFieldWidth() const {
      return m_widthField;
   }

   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

      std::string token{};
      size_t new_pos{};

      new_pos = str.find(m_delimiter, next_pos);
      if (new_pos == next_pos) {
         more = false;
         throw("Field size was 0");
      }
      else if (new_pos == std::string::npos) {
         more = false;
      }

      // new_pos represents field length here
      token = str.substr(next_pos, new_pos - next_pos);

      m_widthField = m_widthField > token.length() ? m_widthField : token.length();

      // adds one to token length (for delimiter) -> assigning a new position
      next_pos += token.length() + 1;
      eraseWhiteSpace(token);

      return token;
   }

   void Utilities::setDelimiter(char newDelimiter) {
      m_delimiter = newDelimiter;
   }

   char Utilities::getDelimiter() {
      return m_delimiter;
   }

   std::string& Utilities::eraseWhiteSpace(std::string& str) {
      unsigned int i = 0;
      if (str != "") {
         while (str[i] == ' ') {
            str.erase(i, 1);
         }
         if (str.length() != 0) {
            i = str.length() - 1;
            while (str[i] == ' ') {
               str.erase(i--, 1);
            }
         }
      }
      return str;
   }

}
