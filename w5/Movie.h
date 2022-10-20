/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-10-19
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

#ifndef MOVIE_H_
#define MOVIE_H_

namespace sdds {

   class Movie
   {
      std::string m_title{};
      std::string m_description{};
      unsigned m_releaseYear{};

   public:
      Movie(){};

      // constructs a movie object based on a string
      Movie(const std::string& strMovie);

      // returns title of the movie
      const std::string& title() const;

      template <typename T>
      void fixSpelling(T& spellChecker) {
         spellChecker(m_title);
         spellChecker(m_description);
      }

      friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
      
   };

}

#endif // MOVIE_H_


