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

string makeUpper( string Word);
void splitOnSpace(string Dict_line, string & Dict_word, string & pronunciation);
bool badword(string new_word);
int countSpaces(string pronunciation);
void phonemify(string pronunciation, string* phonemes);
bool replacePhoneme(string * phonemes, string * diff_phonemes, int j);
bool addPhoneme(string * phonemes, string * diff_phonemes, int j);
bool removePhoneme(string * phonemes, string * diff_phonemes, int j);

int main(){
  string Word; string Dict_line; string Dict_word; string pronunciation;
  //cout << "say a word"<< endl;
  cin >> Word;
  //Word = "accord";
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
      cout<< "Pronunciation    : "<< pronunciation<< endl<< endl;
      foundit = true;
      break; //ends loop after finding the word
    }
  }
  if (!foundit)
    cout<< "Not found"<< endl;
  else{
  //PART TWO-----------------------
    string new_word; string new_pronunciation;
    cout << "Identical        :  ";
    std::ifstream dict("cmudict.0.7a"); //open dictionary
    while(getline(dict,Dict_line)){    //goes through the thing again
      splitOnSpace(Dict_line, new_word, new_pronunciation);  //does the thing again
      if (badword(new_word)) continue;
      if (pronunciation == new_pronunciation && new_word != Word) //compares first and new pronunc
        cout<< new_word<< " ";
    }
    cout << endl;
    dict.close();
  //PART THREE --------------------

    bool replace=false; bool add=false; bool remove=false;
    const int j= countSpaces(pronunciation);
    string ph_array[20]; string* phonemes= ph_array;
    phonemify(pronunciation,phonemes); //puts phonemes into the array
    string* diff_phonemes=nullptr;
    string replaceTotal = "Replace phoneme  : ";
    string addTotal = "Add phoneme      : ";
    string removeTotal = "Remove phoneme   : ";

    std::ifstream dict1("cmudict.0.7a");
    while(getline(dict1,Dict_line)){
      splitOnSpace(Dict_line, new_word, new_pronunciation);  //splits line into word n pronunc
      if (badword(new_word)) continue;
      int m = countSpaces(new_pronunciation);
      if (m == (j+1)){ //for add, need one more phoneme
        string new_array[20]; string * diff_phonemes = new_array;
        phonemify(new_pronunciation,diff_phonemes);
        add = addPhoneme(phonemes, diff_phonemes, j); //returns true if only one is added
        if (add && pronunciation!= new_pronunciation) //compares first and new pronunc
          addTotal = addTotal + " "+ new_word;
      }
      if (m == (j-1)){ //for remove, need one less phoneme
        string new_array[20]; string * diff_phonemes = new_array;
        phonemify(new_pronunciation,diff_phonemes);
        remove = removePhoneme(phonemes, diff_phonemes, j); //returns true if only one is removed
        if (remove && pronunciation!= new_pronunciation) //compares first and new pronunc
          removeTotal = removeTotal + " " + new_word;
      }
      if (m==j){ //for replace, need same # of phonemes
        string new_array[20]; string * diff_phonemes = new_array;
        phonemify(new_pronunciation,diff_phonemes);
        replace = replacePhoneme(phonemes, diff_phonemes, j); //returns true if only one is replaced
        if (replace && pronunciation!= new_pronunciation) //compares first and new pronunc
          replaceTotal = replaceTotal + " "+ new_word;
      }
    } //end of the while loop for parts 3-5
    cout<< addTotal <<endl;
    cout<< removeTotal <<endl;
    cout<< replaceTotal <<endl;
    dict1.close();
  } //end of the else of not finding the og word
  return 0;
}

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
    while (i < Dict_line.size() && !isspace(Dict_line[i])) {
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

bool badword(string new_word){
  for (int i=0; i<new_word.length(); i++){
    if (!isalpha(new_word[i]) && (new_word[i] !='\'' )){
      return true;
    }
  }
  return false; //if good word
}

int countSpaces(string pronunciation) {//
  int i = 0; int j=0;
  while (i < pronunciation.size()) { //counts how many spaces for array
      if (isspace(pronunciation[i]))
        j++;
      i++;
  }
  return(j);
}

void phonemify(string pronunciation, string* phonemes){
  int k=0; int i=0;
  while (i < pronunciation.size()) {
      if (isspace(pronunciation[i])){
        //cout << phonemes[k]<< " "<< endl;
        k++; //moves on to next memory location
      }
      else {
        phonemes[k]= phonemes[k] + pronunciation[i];
      }
      i++;
  }  //*(phonemes+k) is the SAME as phonemes[k]
}
//REPLACE doesnt work
bool replacePhoneme(string * phonemes, string * diff_phonemes, int j){
  int a=0;
  for (int i=0; i<(j+1); i++){ //j PLUS ONE fixed it i think
    if (phonemes[i]!=diff_phonemes[i]){
      a++;
    }
    if (a > 1){
      return false;
    }
  }
  if (a==1){

    return true;
  }
  else {
    return false;
  }
}
//ADD doesnt work
bool addPhoneme(string * phonemes, string * diff_phonemes, int j){
  bool same=true;
  for (int i=0; i<(j+2); i++){
    if (!same && phonemes[i]!=diff_phonemes[i+1]){ //skips over phoneme
        return false;
    }
    if (same && phonemes[i]!=diff_phonemes[i]){
      same = false;
      i--;//this only happens ONCE
    }
  }
  if (same){
    return false;
  }
  else {
    return true;
  }
}
//REMOVE WORKS
bool removePhoneme(string * phonemes, string * diff_phonemes, int j){
  bool same=true;
  for (int i=0; i<(j+1); i++){
    if (!same && phonemes[i+1]!=diff_phonemes[i]){
        return false;
    }
    if (same && phonemes[i]!=diff_phonemes[i]){
      same = false;
      i --;
    }
  }
  if (same){
    return false;
  }
  else {
    return true;
  }
}
