#include <iostream>
#include <cassert>
#include "ai.h"
#include "game.h"
using namespace std;
vector<int> state::get_vector(){
  vector<int> ret;
  int mx = __lg(hash_size) + 1;
  for(int i=3;i>=0;i--){
    int tmp_row = row[i];
    int pw = 1;
    for(int j=0;j<3;j++) pw*=mx;
    while(tmp_row){
      int lgtmp_cell = tmp_row/pw;
      int tmp_cell = 1;
      for(int k=0;k<lgtmp_cell;k++) tmp_cell*=2;
      tmp_row -= lgtmp_cell*pw;
      pw/=mx;
      ret.push_back(tmp_cell);
    }
  }
  reverse(ret.begin(),ret.end());
  return ret;
}
vector<int> state::get_hash(){
  return row;
}
void state::set_hash(const vector<int> &v){
  row.clear();
  int mx = __lg(hash_size) + 1;
  for(int i=0;i<4;i++){
    int hash_val = 0;
    for(int j=0;j<4;j++){
      int pw = 1;
      for(int k=0;k<j;k++) pw*=mx;
      if(v[i*4+j]==0) continue;
      else if(v[i*4+j]<=hash_size) hash_val+=__lg(v[i*4+j])*pw;
      else if(v[i*4+j]>hash_size) hash_val+=__lg(hash_size)*pw;
    }
    row.push_back(hash_val);
  }
}
ai::ai(){
  ai_mode = 0;
}
ai::ai(int mode){
  ai_mode = mode;
}
void ai::init_fake_game(){
  fake_game.clear_cell();
}
void ai::auto_play(ui_game &board){
  board.start_new_ai_game();
  if(ai_mode == 0){
    play_greedy(board);
  } else if(ai_mode == 1){
    play_randomly(board);
  } else if(ai_mode == 2){
    play_cycle(board);
  }
}

void ai::play_randomly(ui_game &board){
  while(!board.check_game_over()){
    board.play_by_direction(rand()%4);
  }
}

void ai::play_cycle(ui_game &board){
  int direction = 0;
  while(!board.check_game_over()){
    if(++direction==4)direction = 0;
    board.play_by_direction(direction);
  }
}

void ai::play_greedy(ui_game &board){
  while(!board.check_game_over()){
    vector<int> now = board.get_board();
    int best_score = 0;
    int best_choice = -1;
    for(int i=0;i<4;i++){
      fake_game.set_board(now);
      int ret_score = fake_game.move_cells(i);
      if(fake_game.get_board()!=now&&ret_score>=best_score)best_choice = i;
    }
    assert(best_choice!=-1);
    board.play_by_direction(best_choice);
  }

}
