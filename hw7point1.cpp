/*Write a function

void sort2(double* p, double* q)
that receives two pointers and sorts the values to which they point. If you call

sort2(&x, &y)
then x <= y after the call.*/
#include <iostream>

void sort2(double* p, double* q){
  if (*p > *q){
    double a = *p;
    *p= *q;
    *q= a;
  }
}

int main(){
  double x; double y;
  std::cin>> x >>y;
  sort2(&x, &y);
  return(0);
}
