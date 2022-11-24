// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include "TreasureMap.h"

namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
           char ch{ '\n' };

           std::ofstream ofs(filename, std::ios::binary | std::ios::trunc);
           if (!ofs) {
              throw("Invalid file name!");
           }
           ofs.write((const char*)&rows, sizeof(rows));
           ofs.write((const char*)&colSize, sizeof(colSize));

           for (unsigned i{ 0 }; i < rows; i++) {
              ofs.write(map[i].c_str(), colSize);
           }
           
            // !TODO
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //       and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //       for the map followed another 4 bytes for the colSize
        //       of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //       the client.


       std::ifstream ifs(filename, std::ios::binary);

       if (!ifs) {
          throw("Invalid file name!");
       }

       ifs.read((char*)&rows, sizeof(rows));
       ifs.read((char*)&colSize, sizeof(colSize));
       map = new std::string[rows];

       char ch{};

       for (unsigned i{ 0 }; i < rows; i++) {
          ch = -1;
          for (unsigned j{ 0 }; j < colSize; j++) {
             ifs.read((char*)&ch, sizeof(ch));
             map[i] += ch;
          };
       }

        // END TODO
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        for (size_t i = 0; i < rows; ++i){
            count += digForTreasure(map[i], mark);
        }

        return count;
    }
}