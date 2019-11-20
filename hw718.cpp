#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Point{
public:
  int x;
  int y;
};

class Triangle {
public:
  Point one;
  Point two;
  Point three;
};

double distform(Point p1, Point p2){
    double sum=(p2.y-p1.y)*(p2.y-p1.y)+ (p2.x-p1.x)*(p2.x-p1.x);
    double distform = sqrt(sum);
    return distform;
  }


double Per(Triangle tri1){
  double length1=distform(tri1.one, tri1.two);
  double length2=distform(tri1.two, tri1.three);
  double length3=distform(tri1.three, tri1.one);
  double per = length1 + length2 + length3;
  return per;
}

int main(){
  Triangle tri1;
  cin >> tri1.one.x>> tri1.one.y>> tri1.two.x>> tri1.two.y>> tri1.three.x>> tri1.three.y;
  double per = Per(tri1);
  cout << per;

  return(0);
}
