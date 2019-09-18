//anne zats project 1b
//idk if this will work
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*int fix (char s, bool neg){ // While the reading operation is a success
    if (s == +){
      return(0);
    }
    if(s == -){
      neg = true; //signals negative number
      return(0);
    }
    if (neg == true){//if there was a negative, make the number negative
      s = s* -1;
      neg=false;//resets negative signal
    }
    return(s);
  }*/

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
      }
      loop+=1;
    }
    cout<< total<< endl;
}
//this does not seem to be working
