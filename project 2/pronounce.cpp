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
  cout << "say a word"<< endl;
  cin >> Word;
  Word= makeUpper(Word);

  std::ifstream dict("cmudict.0.7a"); //open dictionary

  if (dict.fail()) {
      std::cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
  }

  bool foundit = false; string after="";
  while(getline(dict, Dict_line)){   //read line of dictionary
    splitOnSpace(Dict_line, Dict_word, pronunciation);  //splits word n pronunc
    if (Word == Dict_word){     //compares current word to our word
      cout<< "Pronunciation: "<< pronunciation<< endl;
      foundit = true;
      break; //ends loop after finding the word
    }
  }
  if (!foundit)
    cout<< "Not found"<< endl;
  else{
  //PART TWO-----------------------
  std::ifstream dict("cmudict.0.7a"); //open dictionary
    string same_word; string new_pronunciation;
    cout << "Identical: ";
    while(getline(dict,Dict_line)){    //goes through the thing again
      splitOnSpace(Dict_line, same_word, new_pronunciation);  //does the thing again
      if (pronunciation == new_pronunciation && same_word != Word) //compares first and new pronunc
        cout<< same_word<< " ";
    }
    cout << endl;
  }
  return 0;
}
