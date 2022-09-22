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
      
      int m_count = {};

      TennisMatch* m_matches = {};

   public:

      TennisLog();
      TennisLog(const char* fileName);

      TennisLog(const TennisLog& log);
      TennisLog& operator=(const TennisLog& log);

      virtual ~TennisLog();
      void addMatch(const TennisMatch& match);
      TennisLog findMatches(const char* playerName) const;
      TennisMatch operator[](size_t) const;
      operator size_t();
   };

   struct TennisMatch {
      // char pointer ? or std::string ?
      std::string tournID;
      std::string tournName;
      unsigned int matchID;
      std::string winner;
      std::string loser;
   };

   std::ostream& operator<<(std::ostream& os, const TennisMatch& match);


}

#endif