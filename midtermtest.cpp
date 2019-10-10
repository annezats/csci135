#include <iostream>
using namespace std;
#include <string>

int main() {
  string word= "maamaa";
  for (int i=0; i<word.length(); i++){
    if (word[i] == 'a'){
      word= word.substr(0,i)+word.substr(i+1,word.length()-1);
      i=i-1;
      cout<<word<<endl;
    }
  }
  cout<< word<< endl;
  return (0);
}
