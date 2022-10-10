/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-10-10
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

#ifndef BOOK_H_
#define BOOK_H_

#include <string>

namespace sdds {

   class Book
   {
      std::string m_author;
      std::string m_title;
      std::string m_country;
      std::string m_desc;
      size_t m_year;
      double m_price;

   public:
      // default constructor
      Book();

      // constructor that accepts a string to splice
      Book(const std::string& strBook);

      // returns title of book
      const std::string& title() const;

      // returns publication country
      const std::string& country() const;

      // returns publication year
      const size_t& year() const;

      // returns a non-constant price, can be updated by client
      double& price();

      friend std::ostream& operator<<(std::ostream&, Book&);
   };

}

#endif // BOOK_H_