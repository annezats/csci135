//idk if this will work
//anne zats
// csci 135
// aaa

#include <iostream>
#include <cmath>


class Point {
public:
  double x;
  double y;
};

double distance(Point a, Point b){
  double xdiff = b.x-a.x;
  double ydiff = b.y-a.y;
  double dist = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  return(dist);
}

int main(){
  Point a; Point b;
  std::cin>> a.x >>  a.y >> b.x >> b.y;
  double dist1= distance(a,b);
  std::cout << dist1;
}
