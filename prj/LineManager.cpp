

#include <fstream>
#include <vector>
#include <string>

#include "LineManager.h"
#include "Workstation.h"

namespace sdds {

   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      try {
         std::ifstream ifs(file);
         if (!ifs) {
            throw(std::string("file does not exist!"));
         }
         try {
            while (ifs) {
               int x = 0;
            }
         }
         catch (...) {
            throw(std::string("ERROR!"));
         }
         

      }
      catch (...) {
         throw(std::string("error in line manager constructor"));
      }
   }

   void LineManager::reorderStations() {

   }

   bool LineManager::run(std::ostream& os) {
      return false;
   }

   void LineManager::display(std::ostream& os) const {

   }

}
