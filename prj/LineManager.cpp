
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
      Utilities ut;
      ut.setDelimiter('|');

      std::ifstream ifs(file);
      if (!ifs) {
         throw(std::string("File does not exist."));
      }
      try {
         while (ifs.good()) {

            size_t activeStn{}, nextStn{};

            // more is a flag for extractToken()
            // EOL indicates the last item in the 'line manager' (getline gets one token)
            bool more{ true }, EOL{ false };
            std::string line{};
            size_t pos{ 0 };

            std::getline(ifs, line);

            std::string token = ut.extractToken(line, pos, more);

            auto it = std::find_if(begin(stations), end(stations), [=](const Workstation* station)
               {
                  return (station->getItemName() == token);
               });

            activeStn = it - begin(stations);

            if (more) {

               token = ut.extractToken(line, pos, more);

               auto it2 = std::find_if(begin(stations), end(stations), [=](const Workstation* station)
                  {
                     return (station->getItemName() == token);
                  });

               nextStn = it2 - begin(stations);

            }
            else { EOL = true; }

            stations[activeStn]->setNextStation((EOL) ? nullptr : stations[nextStn]);
            
            m_activeLine.push_back(stations[activeStn]);
            
            /*

            bool unique = std::none_of(begin(stations), end(stations), [=](const Workstation* station)
               {
                  auto* ptr = station->getNextStation();
                  return (stations[activeStn]->getItemName() == ((ptr) ? ptr->getItemName() : ""));
               });

            if (unique) {
               m_firstStation = stations[activeStn];
            }

            */
         }

         // search with each station

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

         m_firstStation = stations[first];

      }
      catch (...) {
         throw(std::string("Error: Construction of the Line Manager failed."));
      }
   }

   void LineManager::reorderStations() {

      Workstation* node_1{};
      Workstation* node_2{};

      std::vector<Workstation*> temp;

      node_1 = m_firstStation;
      node_2 = node_1->getNextStation();

      m_firstStation->display(std::cout);
      
      while (node_2) {
         
         temp.push_back(node_2);
         node_1 = node_2;
         node_2 = node_1->getNextStation();
      }

      m_activeLine = temp;
   }

   bool LineManager::run(std::ostream& os) {
      static unsigned calls = 0;
      os << "Line Manager Iteration: " << calls << std::endl;
      return true;
   }

   void LineManager::display(std::ostream& os) const {
      std::for_each(cbegin(m_activeLine), cend(m_activeLine), [&](const Workstation* station)
         {
            station->display(os);
         });
   }

}
