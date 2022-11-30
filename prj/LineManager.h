
#ifndef LINE_MANAGER_H_
#define LINE_MANAGER_H_

#include <vector>
#include "Workstation.h"

namespace sdds {

   class LineManager
   {

      std::vector<Workstation*> m_activeLine{};
      size_t m_cntCustomerOrder{};
      Workstation* m_firstStation{};

   public:

      LineManager(const std::string& file, const std::vector<Workstation*>& stations);

      void reorderStations();

      bool run(std::ostream& os);

      void display(std::ostream& os) const;

   };

}

#endif // !LINE_MANAGER_H_

