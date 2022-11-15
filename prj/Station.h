// Name: Kristjan Punno
// Seneca Student ID: 150695211
// Seneca email: kpunno@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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