
#include <cstdlib>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions
int Chosen_One_array[MAX_ROBOT_NUM];
int size_b = 0;
int size_c = 0;
int Broken_One_array[MAX_ROBOT_NUM];
/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;
	log << "Start!" << endl;
}

bool other_robot_there(Area &area,Loc loc_lookingat){ //just tells you if theres a robot there
  for (int i=0; i< NUM; i++){
    //if (i == id) i++; //skip the current robot's id //unnecessary cuz it wont be next to it anyways
    Loc loc_thisone = area.locate(i);
    if (loc_lookingat.r== loc_thisone.r && loc_lookingat.c== loc_thisone.c ){
      return true;
    }
  }
  return false; //does this if none of the above robots r there
}

bool other_robot_there2(Area &area,Loc loc_lookingat){ //puts the robot's location into the chosen array
  for (int i=0; i< NUM; i++){
    //if (i == id) i++; //skip the current robot's id //unnecessary cuz it wont be next to it anyways
    Loc loc_thisone = area.locate(i);
    if (loc_lookingat.r== loc_thisone.r && loc_lookingat.c== loc_thisone.c ){
      Chosen_One_array[size_c]=i;
      //clog<< "chosen in array"<< endl;
      size_c++;
      return true;
    }
  }
  return false; //does this if none of the above robots r there
}

void remove( int Broken_One_ID, int Chosen_One_ID){
  int index;
  for (int i=0; i<size_b; i++){
    if (Broken_One_array[i]==Broken_One_ID){
      index = i;
      break;
    }
  }
  for (int i = index; i <size_b; i++){
    Broken_One_array[index] = Broken_One_array[index+1];
    Broken_One_array[size_b-1] = 0;
    Chosen_One_array[index] = Chosen_One_array[index+1];
    Chosen_One_array[size_b-1] = 0;
  }
  size_b --;
  size_c --;
}

int find_debris(Area &area,int row, int col, int id){
  //if there is debris right next to it, it goes there
  for (int i=1; i<((ROWS+COLS)/2); i++){
    Loc loc = {row, col+i};
    if (area.inspect(loc) == DEBRIS && !other_robot_there(area, loc))
      return 0;
    loc = {row, (col-i)};
    if (area.inspect(loc) == DEBRIS && !other_robot_there(area, loc))
      return 1;
    loc = {row-i, col};
    if (area.inspect(loc) == DEBRIS && !other_robot_there(area, loc))
        return 2;
    loc = {row+i, col};
    if (area.inspect(loc) == DEBRIS && !other_robot_there(area, loc))
        return 3;
  }
  return (rand()%4);
  //remember that ID now is the variable of the last ID it encountered
}

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) {
	int row = loc.r; // current row and column
	int col = loc.c;
  bool fixit = false;
	if (area.inspect(row, col) == DEBRIS)
		return COLLECT;
	else {
    int Broken_One_ID;
    for (int i = 0; i<size_c; i++){
      if (Chosen_One_array[i]== id){ //checks if this robot is a chosen one
        fixit = true;
        Broken_One_ID = Broken_One_array[i];
      }
    }
    if (fixit){ //deploys to fix it
      Loc loc_broken = area.locate(Broken_One_ID);
      int row_broken = loc.r;
      int col_broken = loc.c;
      if (row > row_broken+1){  return UP;
      }
      if (row < row_broken-1){  return DOWN;
      }
      if (row == row_broken+1 || row == row_broken-1){
        if (col > col_broken){
          log<< "trying to repair part 1" << endl;
          return LEFT;
        }
        if (col < col_broken){
          log<< "trying to repair part 1" << endl;
          return RIGHT;
        }
        else{
          if (row == row_broken+1 && col == col_broken) {
            log<< "trying to repair" << endl;
            remove(Broken_One_ID, id);
            return REPAIR_UP;
          }
          if (row == row_broken-1 && col == col_broken) {
            log<< "trying to repair" << endl;
            remove(Broken_One_ID, id);
            return REPAIR_DOWN;
          }
        }
      }

      //if (row == row_broken+1 && col == col_broken) return REPAIR_UP;
      //if (row == row_broken-1 && col == col_broken) return REPAIR_DOWN;
      //if (row == row_broken && col == col_broken-1) return REPAIR_RIGHT;
      //if (row == row_broken && col == col_broken+1) return REPAIR_LEFT;
      //make it so that once it is fixed, removes from array
    }

    switch(find_debris(area, row,col, id)) {
    case 0:
      return RIGHT;
    case 1:
      return LEFT;
    case 2:
      return UP;
    case 3://default?
      return DOWN;
    }
	}
}

bool break_log(int Broken_One_ID){
  for (int i=0; i<size_b; i++){
    //check if id is in array, if yes return true
    if (Broken_One_array[i] == Broken_One_ID){
      return true;
    }
  }
  Broken_One_array[size_b]= Broken_One_ID;  //if not add it and return false,
  size_b ++;
  return false;
}

void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) {
	log << "Robot " << id << " is damaged." << endl;
  int Broken_One_ID = id;
  bool didnt_scream = break_log(Broken_One_ID);
  int row = loc.r; // current row and column
	int col = loc.c;
  if (didnt_scream){
    for (int i=1; i<((ROWS+COLS)/2); i++){
      Loc loc_lookingat = {row, col+i};
      if (other_robot_there2(area, loc_lookingat)){
        break;
      }
      loc = {row, col-i};
      if (other_robot_there2(area, loc_lookingat)){
        break;
      }
      loc = {row-i, col};
      if (other_robot_there2(area, loc_lookingat)){
        break;
      }
      loc = {row+i, col};
      if (other_robot_there2(area, loc_lookingat)){
        break;
      }
    }
  }
    //set a search for the nearest robot DONE
    //if there is a nearest robot, pass its id DONE using chosen one id
      //alert the nearest robot that it is them;
      //inside robot action, have them go there
}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}
