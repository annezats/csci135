//Write a program that asks the user to input
//•The number of gallons of gas in the tank
//•The fuel efficiency in miles per gallon
//•The price of gas per gallon
//Then print the cost per 100 miles and how far the car can go with the gas in the tank.

//Anne Zats
//csci 135
//gennadiy maryash
//hw 2.10

#include <iostream>
using std::cout;
using std:: endl;
using std:: cin;

int main(){
  double gallons, efficiency, price;
  cout<< "How many gallons in the tank? "<< endl;
  cin>> gallons;
  //cout<< gallons;
  cout<< "Fuel efficiency? "<< endl;
  cin>> efficiency;
  //cout<< efficiency;
  cout<< "price of gallon of gas? "<< endl;
  cin>> price;
  //cout<< price;
  //cost per 100 miles. $/gal / mi/gal *100 =
  double cost_per_100_mi= 100* price / efficiency;
  cout<< "The cost per 100 miles is $"<< cost_per_100_mi<< endl;
  //how far w gas in tank? gallons* mi/gal=main
  double dist_per_tank= gallons* efficiency;
  cout<< "The car can go "<< dist_per_tank<< " miles"<< endl;
return(0);
}
