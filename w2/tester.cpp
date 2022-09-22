
#include <iostream>
#include "TennisLog.h"

using namespace std;
using namespace sdds;

int main(int argc, char** argv) {
   
   std::cout << "Command Line:\n";
   for (int i = 0; i < argc; i++)
      std::cout << i + 1 << ". " << argv[i] << std::endl;

   if (argc != 2)
   {
      std::cerr << std::endl << "***Incorrect number of arguments***" << std::endl;
      return 1;
   }

   TennisLog test("tennis-data.csv");
   TennisMatch test2;

   cout << (test)[1000] << endl;

}