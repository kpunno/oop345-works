#include "Utilities.h"

namespace sdds {



   // initialize class variable
   char Utilities::m_delimiter{};

   void Utilities::setFieldWidth(size_t newWidth) {
      // sets field width of current object to value of parameter
      m_widthField = newWidth;
   }


   size_t Utilities::getFieldWidth() const {
      // returns the field width of the current object
      return m_widthField;
   }

   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
      // uses delim to extract next token from str starting at position next_pos
      // if successful, return a copy of the extracted token (without spaces)
      // update next_pos with the position of the next token, and set more to true, false otherwise

      // ** Reports an exception if a delimiter is found at next_pos
      // ** Updates the current object's m_widthField data member if:
      // its current value is less than the size of the token extracted

      std::string token{};
      size_t new_pos{};

      new_pos = str.find(m_delimiter, next_pos);
      if (new_pos == next_pos) {
         more = false;
         throw("Field width was zero");
      }
      else if (new_pos == std::string::npos) {
         more = false;
      }
      token = str.substr(next_pos, new_pos - next_pos);

      m_widthField = m_widthField > (token.length()) ? m_widthField : (token.length());

      eraseWhiteSpace(token);

      
      

      new_pos++;
      next_pos += new_pos - next_pos;

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
