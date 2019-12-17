#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
//anne zats
//homework 9.5

class Rectangle {
public:
  double get_area(void);
  double get_perimeter(void);
  void resize(double factor);
  Rectangle(double len, double wid);
private:
  double length;
  double width;
};

Rectangle::Rectangle(double len, double wid) {
  length = len;
  width = wid;
}
double Rectangle::get_area(void){
  return length * width;
}
double Rectangle::get_perimeter(void){
  return 2*length + 2*width;
}
void Rectangle::resize(double factor){
  width = width*factor;
  length = length*factor;
}
int main(){
  return(0);
}
