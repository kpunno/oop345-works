#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <string>


/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-09-21
+----------------------------------------------------------------------+
|  I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments.     |
+----------------------------------------------------------------------+
*/

namespace sdds {
   class Dictionary
   {
      std::string m_term{};
      std::string m_definition{};
   public:
      const std::string& getTerm() const { return m_term; }
      const std::string& getDefinition() const { return m_definition; }
      Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{}

      // TODO: Code the missing prototype functions and operators
      //       that the class needs in order to work with the Queue class.
      //       Implement them in the Dictionary.cpp file.

      Dictionary();

      // an operator returning true if two m_term strings are equal
      bool operator==(const Dictionary&);

      // a catered display of an instance of Dictionary
      std::ostream& display(std::ostream& os = std::cout);
      
   };

   // helper function aids in inserting Dictionary into ostream
   std::ostream& operator<<(std::ostream&, Dictionary dic);
}

#endif // DICTIONARY_H_

