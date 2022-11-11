
#ifndef STATION_H_
#define STATION_H_

#include <string>

namespace sdds {

   class Station
   {
      int m_id{};
      std::string m_name{};
      std::string m_desc{};
      unsigned m_serial{};
      unsigned m_quantity{};
      static size_t m_widthField;
      static int m_idGenerator;

   public:

      Station(const std::string&);

      const std::string& getItemName() const;

      size_t getNextSerialNumber();

      size_t getQuantity() const;

      void updateQuantity();

      void display(std::ostream& os, bool full) const;
   };

}

#endif // STATION_H_