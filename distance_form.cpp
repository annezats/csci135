double distance (double a[], double v[], int len){
  double sum=0;
  for (int i=0; i< len, i++){
    sum = sum + (b[i]-a[i])*(b[i]-a[i]);
  }
  return sum;
}

double raw_frequencies[]{5,4,6,3} //array for frequency of letters

double count_letters (string s; char c){
  num_of_letters = 0;
  for (int i= 0; i< s.length(); i++){
    if (s[i]==c){
      num_of_letters= num_of_letters + 1;
    }
  }
  return num_of_letters; //this only counts for one letter, put this inside
  //a loop that goes through the 26 letters, then sticks each value/s.length into an array
}



//in a loop of 26 take your ciphertext and shift it, that's test string
//build a vector of frequencies for the test string
    //^^that's what count_letters is doing half of
// find the distane between test vector and freq vector
  // that's what distance() does^^
//if the difference in distance is smallest, update "minimum distance"
