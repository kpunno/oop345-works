/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-09-21
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

#ifndef TENNIS_LOG_H_
#define TENNIS_LOG_H_

#include <iostream>
#include <string>

namespace sdds {

   struct TennisMatch;

   class TennisLog {
      
      // counts the number of stored records in the current object
      int m_count = {};

      // array containing TennisMatch records
      TennisMatch* m_matches = {};

   public:

      // init to safe empty
      TennisLog();

      // reads from a file, creates a dynamic array for which to store match data
      TennisLog(const char*);

      // copy constructor
      TennisLog(const TennisLog& log);

      // copy assignment
      TennisLog& operator=(const TennisLog& log);

      // move constructor
      TennisLog(TennisLog&&);

      // move assignment
      TennisLog& operator=(TennisLog&&);

      // user-defined destructor
      virtual ~TennisLog();

      // appends a match to end of TennisMatch array
      void addMatch(const TennisMatch& match);

      // returns an object of all matches containing the supplied playerName
      TennisLog findMatches(const char* playerName) const;

      // returns a TennisMatch structure at the specified index in TennisMatch array
      TennisMatch operator[](size_t) const;

      // returns the size of the current object's TennisMatch array
      operator size_t();
   };

   struct TennisMatch {
      std::string tournID{};
      std::string tournName{};
      unsigned int matchID{};
      std::string winner{};
      std::string loser{};
   };

   // displays a formatted instance of TennisMatch
   std::ostream& operator<<(std::ostream& os, const TennisMatch& match);


}

#endif // TENNIS_LOG_H_