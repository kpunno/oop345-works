
#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "CustomerOrder.h"

namespace sdds {

   size_t CustomerOrder::m_widthField{};

   CustomerOrder::CustomerOrder() {}

   CustomerOrder::CustomerOrder(const std::string& record) {
      Utilities ut;
      // customer name
      // order name
      // list of items making up the order (at least one)
      // updates width field

      size_t pos{};
      bool more{ true };

      m_name = ut.extractToken(record, pos, more);
      m_product = ut.extractToken(record, pos, more);

      size_t rewind_to = pos;

      while (more) {
         ut.extractToken(record, pos, more);
         m_cntItem++;
      }

      if (m_cntItem) {
         pos = rewind_to;
         bool more{ true };
         m_lstItem = new Item* [m_cntItem]{};

         for (int i{ 0 }; i < m_cntItem; i++) {
            m_lstItem[i] = new Item(ut.extractToken(record, pos, more));
            m_widthField = ut.getFieldWidth() > m_widthField ? ut.getFieldWidth() : m_widthField;
         }
      }
      
   }

   CustomerOrder::CustomerOrder(const CustomerOrder& order) {
      throw("EXCEPTION");
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
      m_name = order.m_name;
      m_product = order.m_product;
      m_cntItem = order.m_cntItem;
      m_lstItem = order.m_lstItem;
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
      // promises that it doesn't throw
      CustomerOrder test;
      return test;
   }

   CustomerOrder::~CustomerOrder() {

   }

   bool CustomerOrder::isOrderFilled() const {
      // returns true if all items in the order have been filled
      // false otherwise
      return false;
   }

   bool CustomerOrder::isItemFilled(const std::string& item) const {
      // returns true if all items specified by argument have been filled
      // if item doesn't exist, returns true
      return false;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) {
      // modifier fills ONE item in the current order
      // ITEM is specified in the argument
      // if the order doesn't contain the item, function does nothing
      
   }

   void CustomerOrder::display(std::ostream& os) {
      os << m_name << " - " << m_product << std::endl;
      for (int i{ 0 }; i < m_cntItem; i++) {
         os << std::setfill('0');
         os << "[" << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
         os << std::setfill(' ');
         os << std::setw(m_widthField) << m_lstItem[i]->m_itemName;
         os << " - ";
         os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
         os << std::endl;
      }
   }

}
