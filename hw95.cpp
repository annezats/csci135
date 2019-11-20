#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
//anne zats
//homework 9.5

Class Rectangle {
public:
  double length= get_length();
  double width= get_width();
  double get_area(void){
    return length * width;
  }
  double get_perimeter(void){
    return 2*length + 2*width;
  }
  void resize(double factor);
}

void Rectangle::resize(double factor){
  width = width*factor;
  length = length*factor;

int main(){
  return(0);
}
