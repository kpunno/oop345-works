// Name: Kristjan Punno
// Seneca Student ID: 150695211
// Seneca email: kpunno@myseneca.ca
// Date of completion: 2022-11-23
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

         for (size_t i{ 0 }; i < m_cntItem; i++) {
            m_lstItem[i] = new Item(ut.extractToken(record, pos, more));
            m_widthField = ut.getFieldWidth() > m_widthField ? ut.getFieldWidth() : m_widthField;
         }
      }
      
   }

   CustomerOrder::CustomerOrder(const CustomerOrder& order) {
      throw("Copy construction is disallowed!");
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
      *this = std::move(order);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
      
      if (this != &order) {
         if (m_cntItem) {
            for (size_t i{ 0 }; i < m_cntItem; i++) {
               delete m_lstItem[i];
            }
         }
         delete [] m_lstItem;

         m_cntItem = order.m_cntItem;
         m_lstItem = order.m_lstItem;
         
         order.m_cntItem = 0;
         order.m_lstItem = nullptr;

         m_name = order.m_name;
         m_product = order.m_product;
         
      }
      return *this;
   }

   CustomerOrder::~CustomerOrder() {
      for (size_t i{ 0 }; i < m_cntItem; i++) {
         delete m_lstItem[i];
      }
      delete [] m_lstItem;
      m_lstItem = nullptr;
   }

   bool CustomerOrder::isOrderFilled() const {
      // returns true if all items in the order have been filled
      // false otherwise
      bool filled{ true };
      for (size_t i{ 0 }; i < m_cntItem; i++) {
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
      unsigned count{};
      for (size_t i{ 0 }; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == item && !m_lstItem[i]->m_isFilled) {
               filled = false;
         }
      }
      return filled;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) {
      // modifier fills ONE item in the current order
      // ITEM is specified in the argument
      // if the order doesn't contain the item, function does nothing

      bool found{ false };

      for (size_t i{ 0 }; i < m_cntItem && !found; i++) {
         if (station.getItemName() == m_lstItem[i]->m_itemName && !m_lstItem[i]->m_isFilled) {
            if (station.getQuantity()) {

               // item is now filled, loop will break
               m_lstItem[i]->m_isFilled = found = true;

               // serial number is updated
               m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();

               // station's inventory is updated
               station.updateQuantity();

               os << "    Filled ";
               os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
            else {
               os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
         }
      }
   }

   void CustomerOrder::display(std::ostream& os) const {
      os << m_name << " - " << m_product << std::endl;
      for (size_t i{ 0 }; i < m_cntItem; i++) {
         os << std::setfill('0');
         os << "[" << std::setw(6) << std::right << m_lstItem[i]->m_serialNumber << "] ";
         os << std::setfill(' ') << std::left;
         os << std::setw(m_widthField) << m_lstItem[i]->m_itemName;
         os << " - ";
         os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
         os << std::endl;
      }
   }

}
