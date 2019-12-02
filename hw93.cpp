#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
//anne zats
//homework 9.3

class Circuit {
public:
  int get_first_switch_state(); // 0 for down, 1 for up
  int get_second_switch_state();
  int get_lamp_state(); // 0 for off, 1 for on
  void toggle_first_switch();
  void toggle_second_switch();
private:
  int lamp_state=0;
  int first_Switch=0;
  int second_Switch=0;
};

int Circuit::get_first_switch_state(){
  return first_Switch;
} // 0 for down, 1 for up
int Circuit::get_second_switch_state(){
  return second_Switch;
}
int Circuit::get_lamp_state(){
  return lamp_state;
} // 0 for off, 1 for on
void Circuit::toggle_first_switch(){
  lamp_state = (lamp_state + 1)%2;
  first_Switch = (first_Switch + 1)%2;
}
void Circuit::toggle_second_switch(){
  lamp_state = (lamp_state + 1)%2;
  second_Switch = (second_Switch + 1)%2;
}
int main(){
  return (0);
}
