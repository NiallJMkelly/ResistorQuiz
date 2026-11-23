#include <string>
#include <array>

class colour{
public:
 inline static const std::array<std::string,10> colours ={"black","brown","red","orange",
    "yellow","green","blue","violet","grey","white"};
 // from 0 to 9 array
 inline static std::string getColour(int band){
 //take in int value
 //return string for answer.
   return colours.at(band);
  }
};