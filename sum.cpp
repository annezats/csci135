#include <iostream>
using namespace std;
int main() {
    int s;
    int total= 0;
    while(cin >> s) { // While the reading operation is a success
        total= total + s;
        //cout << s << endl;  // print the read word
    }
    cout<< total<< endl;

}
