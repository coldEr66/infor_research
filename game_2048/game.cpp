#include <utility>
#include <vector>
#include "game.h"
using namespace std;
game::game(){
  srand(time(NULL));
}
void game::clear_cell(){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cell[i][j] = 0;
    }
  }
}

void game::set_board(vector<int> input){
  for(int i=0;i<16;i++){
    cell[i/4][i%4] = input[i];
  }
}

vector<int> game::get_board(){
  vector<int> ret;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      ret.push_back(cell[i][j]);
    }
  }
  return ret;
}

bool game::check_game_over(){ //return if the game's over
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(cell[i][j]==0) return false;
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
      if(cell[i][j]==cell[i][j+1]) return false;
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
      if(cell[j][i]==cell[j+1][i]) return false;
    }
  }
  return true;
}

int game::move_cells(int direction){ //move cells {0,1,2,3} = {up,right,down,left}
  int ret_score = 0;
  if(direction == 0){ //up
    for(int j=0;j<4;j++){ //numbers of cols
      for(int i=1;i<4;i++){ //index of cell to move
        int k; //bottom most not empty cell
        for(k=i-1;k>=0;k--){
          if(cell[k][j] != 0)break;
        }
        if(cell[i][j] == cell[k][j]){
          cell[k][j] += cell[i][j];
          ret_score += cell[k][j];
          cell[i][j] = 0;
        } else {
          int tmp = cell[i][j];
          cell[i][j] = 0;
          cell[k+1][j] = tmp;
        }
      }
    }
  } else if(direction == 1) { //right
    for(int i=0;i<4;i++){ //numbers of rows
      for(int j=2;j>=0;j--){ //index of cell to move
        int k; //left most not empty cell
        for(k=j+1;k<4;k++){
          if(cell[i][k] != 0)break;
        }
        if(cell[i][j] == cell[i][k]){
          cell[i][k] += cell[i][j];
          ret_score += cell[i][k];
          cell[i][j] = 0;
        } else {
          int tmp = cell[i][j];
          cell[i][j] = 0;
          cell[i][k-1] = tmp;
        }
      }
    }
  } else if(direction == 2) {
    for(int j=0;j<4;j++){ //numbers of cols
      for(int i=2;i>=0;i--){ //index of cell to move
        int k; //top most not empty cell
        for(k=i+1;k<4;k++){
          if(cell[k][j] != 0)break;
        }
        if(cell[i][j] == cell[k][j]){
          cell[k][j] += cell[i][j];
          ret_score += cell[k][j];
          cell[i][j] = 0;
        } else {
          int tmp = cell[i][j];
          cell[i][j] = 0;
          cell[k-1][j] = tmp;
        }
      }
    }
  } else if(direction == 3) { //left
    for(int i=0;i<4;i++){ //numbers of rows
      for(int j=1;j<4;j++){ //index of cell to move
        int k; //right most not empty cell
        for(k=j-1;k>=0;k--){
          if(cell[i][k] != 0)break;
        }
        if(cell[i][j] == cell[i][k]){
          cell[i][k] += cell[i][j];
          ret_score += cell[i][k];
          cell[i][j] = 0;
        } else {
          int tmp = cell[i][j];
          cell[i][j] = 0;
          cell[i][k+1] = tmp;
        }
      }
    }
  }
  return ret_score;
}

int game::play_by_direction(int direction){
  vector<int> prev_state = get_board();
  int ret = move_cells(direction);
  if(prev_state != get_board())generate_random_cell();
  if(check_game_over())ret -= 1000000000;
  return ret;
}
void game::generate_random_cell(){
  vector<pair<int,int> > available;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      if(cell[i][j]==0)available.push_back({i,j});

  if(available.empty())return;
  int choice = rand() % int(available.size());
  cell[available[choice].first][available[choice].second] = (rand()%10?2:4);
  return;
}
