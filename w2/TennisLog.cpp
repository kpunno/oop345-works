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

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "TennisLog.h"

namespace sdds {

   int TennisLog::m_mCount = 0;

   TennisLog::TennisLog() {};

   TennisLog::TennisLog(const char* fileName) {

      //format
      // tourney_id,tourney_name,match_id,winner_name,loser_name
      std::string temp;
      std::ifstream ifs;
      ifs.open(fileName);
      if (ifs.is_open()) {

         //skipping format line
         ifs.ignore(1000, '\n');

         while (!ifs.fail()) {
            std::getline(ifs, temp, '\n');
            m_mCount++;
         }

         // rewind file pointer
         ifs.clear();
         ifs.seekg(0);

         // skipping format line
         ifs.ignore(1000, '\n');

         m_matches = new TennisMatch[m_mCount];
         for (int i = 0; i < m_mCount; i++) {
            if (i == 25000) {
               std::cout << "HERE";
            }
            getline(ifs, m_matches[i].tournID, ',');
            getline(ifs, m_matches[i].tournName, ',');
            ifs >> m_matches[i].matchID;
            ifs.ignore();
            getline(ifs, m_matches[i].winner, ',');
            getline(ifs, m_matches[i].loser);
         }
      }
   }

   void TennisLog::addMatch(const TennisMatch& match) {
      // uses move to change control to temporary array, then switch pointer back
   }

   TennisLog TennisLog::findMatches(const char* playerName) {



      // search for records containing provided playerName
      // return an array of tennisMatches containing aforementioned player
   }

   TennisMatch TennisLog::operator[](size_t index) {
      TennisMatch tennisMatch;
      if (!m_mCount) {
         return tennisMatch;
      }
      else {
         if (index < 0) index = 0;
         return m_matches[index % m_mCount];
      }
      // returns a tennismatch
   }

   TennisLog::operator size_t() {
      return (size_t)(m_mCount);
   }

   // testing only ***
   void TennisLog::display() const {
      std::cout << m_mCount;
   }

   std::ostream& operator<<(TennisMatch& match, std::ostream& os) {
      os << std::setfill('.');
      os << std::setw(20) << std::right << "Tourney ID : ";
      os << std::setw(20) << std::left << match.tournID;
      return os;
   }
}