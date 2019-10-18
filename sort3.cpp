#include <iostream>



void sort3( int a, int b, int c){
   if (a>b){
      if (a<c){
      //bac FLIP AB
      int z= b;
      b= a;
      a=z;
      }
      else{
         if (b<c){
            //bca ALL FLIP
            int y= a;
            int z= b;
            a=c;
            b=y;
            c=z;
         }
         else{
            //cba FLIP AC
            int z= c;
            c= a;
            a=z;
         }
      }
    }
   if (a<b){
      if (a>c){
      //cab ALL FLIP
      int y= a;
      int z= b;
      a=c;
      b=y;
      c=z;
      }
      else{
         if (b<c){
            //abc NO CHANGE
         }
         else{
            //acb FLIP CB
            int z= b;
            b= c;
            c=z;
         }
      }
    }
   std::cout << a << b<< c<< std::endl;
}

int main(){
  int a; int b; int c;
  std::cin>> a>>b>>c;
  sort3(a,b,c);
  return(0);
}
