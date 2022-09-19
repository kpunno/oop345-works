


#ifndef TENNIS_LOG_H_
#define TENNIS_LOG_H_

namespace sdds {

   class TennisLog {
      TennisMatch* m_match;
      static int m_mCount;
   };

   struct TennisMatch {
      // char pointer ? or std::string ?
      char* tournID{};
      char* tournName{};
      unsigned int matchID{};
      char* winner{};
      char* loser{};
   };




}

#endif