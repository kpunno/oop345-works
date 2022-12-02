
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Utilities.h"
#include "LineManager.h"
#include "Workstation.h"


namespace sdds {

   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {

      // instance of utilities for token extraction
      // assuming file may contain whitespace
      Utilities ut;
      ut.setDelimiter('|');

      std::ifstream ifs(file);
      if (!ifs) {
         throw(std::string("File does not exist."));
      }
      try {
         while (ifs.good()) {

            // represent indices of the stations vector
            // to give meaning to the list of linked objects
            size_t activeStn{}, nextStn{};

            // more is a flag for extractToken()
            // EOL indicates the last item in the 'line manager' (getline gets one token)
            bool more{ true }, EOL{ false };

            // line : extracted token
            std::string line{};

            // pos : position in extracted char array
            size_t pos{ 0 };

            // read line, extract token
            std::getline(ifs, line);
            std::string token = ut.extractToken(line, pos, more);

            // find the station that matches the first token
            auto it = std::find_if(begin(stations), end(stations), [=](const Workstation* station)
               {
                  return (station->getItemName() == token);
               });

            // get index of matching station
            activeStn = it - begin(stations);

            // if another token exists
            if (more) {

               token = ut.extractToken(line, pos, more);

               auto it2 = std::find_if(begin(stations), end(stations), [=](const Workstation* station)
                  {
                     return (station->getItemName() == token);
                  });

               nextStn = it2 - begin(stations);

            }
            // if another token does not exist
            // this object is the last in the line
            else { EOL = true; }

            // if this object is the end of the line, the next station is a null pointer
            stations[activeStn]->setNextStation((EOL) ? nullptr : stations[nextStn]);

            // add to active line : 
            // the new object that references next object in the line
            m_activeLine.push_back(stations[activeStn]);

         }

         // this search finds the station with no previous station
         // then sets the found station to m_firstStation
         auto it = std::find_if(begin(stations), end(stations), [=](const Workstation* station)
            {
               bool unique = std::none_of(begin(stations), end(stations), [=](const Workstation* station2)
                  {
                     auto* ptr = station2->getNextStation();
                     return (station->getItemName() == ((ptr) ? ptr->getItemName() : ""));
                  });
               return unique;
            });

         size_t first = it - begin(stations);

         // set first station
         m_firstStation = stations[first];

         m_cntCustomerOrder = g_pending.size();

      }
      catch (...) {
         throw(std::string("Error: Construction of the Line Manager failed."));
      }
   }

   void LineManager::reorderStations() {

      Workstation* activeStn{};
      Workstation* nextStn{};

      std::vector<Workstation*> ordered_stations;

      activeStn = m_firstStation;
      nextStn = activeStn->getNextStation();

      
      ordered_stations.push_back(activeStn);

      while (nextStn) {

         ordered_stations.push_back(nextStn);
         activeStn = nextStn;
         nextStn = activeStn->getNextStation();
      }

      m_activeLine = ordered_stations;
   }

   bool LineManager::run(std::ostream& os) {

      static size_t calls = 0;
      calls++;
      if (calls == 6) {
         int x = 0;
      }
      os << "Line Manager Iteration: " << calls << std::endl;

      // throws here
      if (g_pending.size()) {
         *m_firstStation += std::move(g_pending.front());
         g_pending.pop_front();
      }
      
      if (calls == 20) {
         int x = 0;
      }
      
      
      for (Workstation* e : m_activeLine) {
         e->fill(os);
      }

      for (Workstation* e : m_activeLine) {
         e->attemptToMoveOrder();
      }

      return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();
   }

   void LineManager::display(std::ostream& os) const {
      std::for_each(cbegin(m_activeLine), cend(m_activeLine), [&](const Workstation* station)
         {
            station->display(os);
         });
   }

}
