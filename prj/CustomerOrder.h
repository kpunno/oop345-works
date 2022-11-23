// Name: Kristjan Punno
// Seneca Student ID: 150695211
// Seneca email: kpunno@myseneca.ca
// Date of completion: 2022-11-14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMER_ORDER_H_
#define CUSTOMER_ORDER_H_

#include <string>
#include "Station.h"

namespace sdds {

   class CustomerOrder
   {
      struct Item {
         std::string m_itemName;
         size_t m_serialNumber{ 0 };
         bool m_isFilled{ false };

         Item(const std::string& src) : m_itemName(src) {};
      };

      // name of customer
      std::string m_name{};

      // name of product
      std::string m_product{};

      // counts the number of items in an order
      size_t m_cntItem{};

      // the resource that the class manages, array of pointers
      Item** m_lstItem{};

      static size_t m_widthField;

   public:

      CustomerOrder();

      CustomerOrder(const std::string&);

      CustomerOrder(const CustomerOrder&);

      CustomerOrder& operator=(const CustomerOrder&) = delete;

      CustomerOrder(CustomerOrder&&) noexcept;

      CustomerOrder& operator=(CustomerOrder&&) noexcept;

      ~CustomerOrder();

      bool isOrderFilled() const;

      bool isItemFilled(const std::string&) const;

      void fillItem(Station&, std::ostream&);

      void display(std::ostream&);

   };

}

#endif // CUSTOM_ORDER_H_