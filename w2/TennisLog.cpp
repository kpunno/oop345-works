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
#include <string>
#include "TennisLog.h"
#include "Timer.h"

namespace sdds {

   TennisLog::TennisLog() {};

   TennisLog::TennisLog(const char* fileName) {
      std::string temp;
      std::ifstream ifs;
      ifs.open(fileName);
      if (ifs.is_open()) {

         //skipping file's format line
         ifs.ignore(1000, '\n');

         while (!ifs.fail()) {
            std::getline(ifs, temp, '\n');
            if (strcmp(temp.c_str(), "") != 0) m_count++;
         }

         // rewind file pointer
         ifs.clear();
         ifs.seekg(0);

         // skipping file's format line
         ifs.ignore(1000, '\n');

         m_matches = new TennisMatch[m_count];
         for (int i = 0; i < m_count; i++) {
            getline(ifs, m_matches[i].tournID, ',');
            getline(ifs, m_matches[i].tournName, ',');
            ifs >> m_matches[i].matchID;
            ifs.ignore();
            getline(ifs, m_matches[i].winner, ',');
            getline(ifs, m_matches[i].loser);
         }
      }
   }

   TennisLog::TennisLog(const TennisLog& log) {
      operator=(log);
   }

   TennisLog& TennisLog::operator=(const TennisLog& log) {
      if (this != &log) {
         m_count = log.m_count;
         m_matches = new TennisMatch[log.m_count];
         for (int i = 0; i < m_count; i++) {
            this->m_matches[i] = log.m_matches[i];
         }
      }
      return *this;
   }

   TennisLog::TennisLog(TennisLog&& log) {
      *this = std::move(log);
   }

   TennisLog& TennisLog::operator=(TennisLog&& log) {
      if (this != &log) {
         delete[] m_matches;
         m_count = log.m_count;
         log.m_count = 0;
         m_matches = log.m_matches;
         log.m_matches = nullptr;
      }
      return *this;
   }

   TennisLog::~TennisLog() {
      delete[] m_matches;
   }

   void TennisLog::addMatch(const TennisMatch& match) {
      TennisLog temp;
      temp.m_matches = new TennisMatch[++m_count];
      for (int i = 0; i < (m_count - 1); i++) {
         temp.m_matches[i] = m_matches[i];
      }
      temp.m_matches[m_count - 1] = match;
      delete[] m_matches;
      m_matches = new TennisMatch[m_count];
      for (int i = 0; i < m_count; i++) {
         m_matches[i] = temp.m_matches[i];
      }
   }

   // can this be upgraded to store the indexes instead? ?
   TennisLog TennisLog::findMatches(const char* playerName) const {
      // loop variable
      int i;

      // counter for matching names
      size_t logSize = 0;

      // loop finds array size for return object's TennisMatch array
      for (i = 0; i < m_count; i++) {

         // if parameter is found in a record
         if (strcmp((*this)[i].winner.c_str(), playerName) == 0 || strcmp((*this)[i].loser.c_str(), playerName) == 0) {
            logSize++;
         }
      }
      // return object
      TennisLog playerLog;
      playerLog.m_count = logSize;
      playerLog.m_matches = new TennisMatch[logSize];

      int j = 0;
      for (i = 0; i < m_count && j < logSize; i++) {
         if (strcmp((*this)[i].winner.c_str(), playerName) == 0 || strcmp((*this)[i].loser.c_str(), playerName) == 0) {
            playerLog.m_matches[j] = (*this)[i];
            j++;
         }
      }
      return playerLog;
   }

   TennisMatch TennisLog::operator[](size_t index) const {
      TennisMatch tennisMatch;
      return m_count > 0 ? m_matches[index % m_count] : tennisMatch;
   }

   TennisLog::operator size_t() {
      return (size_t)(m_count);
   }

   std::ostream& operator<<(std::ostream& os, const TennisMatch& match) {
      if (strcmp(match.tournID.c_str(), "") == 0) {
         std::cout << "Empty Match";
      }
      else {
         os << std::setfill('.');
         os << std::setw(20) << std::right << "Tourney ID";
         os << std::setw(3) << " : ";
         os << std::setw(30) << std::left << match.tournID << std::endl;

         os << std::setfill('.');
         os << std::setw(20) << std::right << "Match ID";
         os << std::setw(3) << " : ";
         os << std::setw(30) << std::left << match.matchID << std::endl;

         os << std::setfill('.');
         os << std::setw(20) << std:: right << "Tourney";
         os << std::setw(3) << " : ";
         os << std::setw(30) << std::left << match.tournName << std::endl;

         os << std::setfill('.');
         os << std::setw(20) << std::right << "Winner";
         os << std::setw(3) << " : ";
         os << std::setw(30) << std::left << match.winner << std::endl;

         os << std::setfill('.');
         os << std::setw(20) << std::right << "Loser";
         os << std::setw(3) << " : ";
         os << std::setw(30) << std::left << match.loser << std::endl;

         os << std::setfill(' ');
      }
      return os;
   }
}