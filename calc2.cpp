//anne zats project 1c
//idk if this will work
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    int num;
    char op;
    int total=0;
    bool neg = false;
    //bool read= true;
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
        if(op == ';'){
          cout<< total<< endl;
          total = 0;
          loop = -1;
        }
      }
      loop+=1;
    }
}
//this does not seem to be working
