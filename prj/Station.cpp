
#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"

namespace sdds {

   int Station::m_idGenerator{ 0 };
   size_t Station::m_widthField{ 0 };

   Station::Station(const std::string& str) {
      Utilities ut{};
      size_t pos{};
      bool more{ true };
      m_id = ++m_idGenerator;

      m_name = ut.extractToken(str, pos, more);
      m_serial = stoi(ut.extractToken(str, pos, more));
      m_quantity = stoi(ut.extractToken(str, pos, more));
      m_widthField = ut.getFieldWidth() > m_widthField ? ut.getFieldWidth() : m_widthField;
      m_desc = ut.extractToken(str, pos, more);
   }

   const std::string& Station::getItemName() const {
      return m_name;
   }

   size_t Station::getNextSerialNumber() {
      return m_serial++;
   }

   size_t Station::getQuantity() const {
      return m_quantity;
   }

   void Station::updateQuantity() {
      m_quantity > 0 ? --m_quantity : m_quantity;
   }

   void Station::display(std::ostream& os, bool full) const {
      os << std::right << std::setfill('0');
      os << std::setw(3) << m_id << " | ";
      os << std::left << std::setfill(' ');
      os << std::setw(m_widthField) << m_name << " | ";
      os << std::right << std::setfill('0');
      os << std::setw(6) << m_serial << " | ";
      

      if (full) {
         os << std::setfill(' ');;
         os << std::right;
         os << std::setw(4) << m_quantity << " | ";
         os << std::left;
         os << m_desc;
      }
      os << std::endl;
   }

}
