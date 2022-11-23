// Name: Kristjan Punno
// Seneca Student ID: 150695211
// Seneca email: kpunno@myseneca.ca
// Date of completion: 2022-11-14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "CustomerOrder.h"

namespace sdds {

   size_t CustomerOrder::m_widthField{};

   CustomerOrder::CustomerOrder() {}

   CustomerOrder::CustomerOrder(const std::string& record) {
      Utilities ut;

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
      *this = std::move(order);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
      
      if (this != &order) {
         m_name = order.m_name;
         m_product = order.m_product;
         m_cntItem = order.m_cntItem;
         m_lstItem = order.m_lstItem;

         order.m_cntItem = 0;
         order.m_lstItem = nullptr;
      }
      return *this;
   }

   CustomerOrder::~CustomerOrder() {
      for (unsigned i{ 0 }; i < m_cntItem; i++) {
         if (m_lstItem[i] != nullptr) {
            delete m_lstItem[i];
         }
      }
      delete [] m_lstItem;
   }

   bool CustomerOrder::isOrderFilled() const {
      // returns true if all items in the order have been filled
      // false otherwise
      bool filled{ true };
      for (unsigned i{ 0 }; i < m_cntItem; i++) {
         if (!m_lstItem[i]->m_isFilled) {
            filled = false;
         }
      }
      return filled;
   }

   bool CustomerOrder::isItemFilled(const std::string& item) const {
      // returns true if all items specified by argument have been filled
      // if item doesn't exist, returns true
      bool filled{ true };
      for (unsigned i{ 0 }; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == item) {
            if (!m_lstItem[i]->m_isFilled) {
               filled = false;
            }
         }
      }
      return filled;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) {
      // modifier fills ONE item in the current order
      // ITEM is specified in the argument
      // if the order doesn't contain the item, function does nothing

      bool found{ false };

      for (unsigned i{ 0 }; i < m_cntItem && !found; i++) {
         if (station.getItemName() == m_lstItem[i]->m_itemName) {
            
            // item is now filled, loop will break
            m_lstItem[i]->m_isFilled = found = true;

            // serial number is updated
            m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();

            // station's inventory is updated
            station.updateQuantity();

            os << "    " << "Filled ";
            os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
         }
      }
   }

   void CustomerOrder::display(std::ostream& os) {
      os << m_name << " - " << m_product << std::endl;
      for (unsigned i{ 0 }; i < m_cntItem; i++) {
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