//anne zats project 1d
//idk if this will work
//WDYM another comment
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    int num;
    char op;
    int total=0;
    bool neg = false;
    int array1[100];
    int loop = 0;
    while (cin.eof() == false){   //while there is input
      if (loop%2 == 0){    //alternates int and char
        cin >> num;  //reads int
        if (neg == true){//if there was a negative, make the number negative
          num = num* -1;
          neg=false;//resets negative signal
        }
        total= total + num;
      }
      else{
        cin>> op; // reads char
        if(op == '-'){
          neg = true; //signals negative number
        }
        if (op== '^'){
          total= total - num;
          if (num< 0){
            num=num*num;
            num=num*-1;
          }
          else{
            num=num*num;
          }
          total = total + num;
          loop = loop - 1;
        }
        if(op == ';'){
          cout<< total<< endl;
          total = 0;
          loop = -1;
        }
      }
      loop+=1;
    }
}
//easier way to do it:
/*while (cin >> int num){
 do num stuff;
 cin >> op;
 if op do op stuff etc;
}
*/
