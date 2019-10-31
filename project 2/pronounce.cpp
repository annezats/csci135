//anne zats
//csci 135
//project 2

#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string makeUpper( string Word){
  string newWord ="";
  for (int i=0; i< Word.length(); i++){
    if (Word[i]>= 97 && isalpha(Word[i])){
      newWord= newWord + (char(Word[i]- 32));
    }
    else {
      newWord= newWord + Word[i];
    }
  }
  return newWord;
}

void splitOnSpace(string Dict_line, string & Dict_word, string & pronunciation) {
  // accumulate before space
    Dict_word="";
    pronunciation="";
    int i = 0;
    while (i < Dict_line.size() && not isspace(Dict_line[i])) {
        Dict_word = Dict_word + Dict_line[i];
        i++;
    }
  // skip the space
    i++;
    // accumulate after space
    while (i < Dict_line.size()) {
        pronunciation = pronunciation + Dict_line[i];
        i++;
    }
}

int main(){
  string Word; string Dict_line; string Dict_word; string pronunciation;
  cin >> Word;
  Word= makeUpper(Word);

  std::ifstream dict("cmudict.0.7a"); //open dictionary

  if (dict.fail()) {
      std::cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
  }

  // string firstline;  //unnecessary first 54 lines
  // for (int i=0; i<=54; i++){
  //   getline(dict, firstline);
  // }

  bool foundit = false; string after="";
  while(getline(dict, Dict_line)){   //read line of dictionary
    splitOnSpace(Dict_line, Dict_word, pronunciation);
    //cout<< Dict_word<< '\n';
    if (Word == Dict_word){
      cout<< "Pronunciation: "<< pronunciation<< endl;
      foundit = true;
    }
  }
  if (!foundit){
    cout<< "Not found"<< endl;
  }
  return 0;
}
