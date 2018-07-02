#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include "ai.h"
#include "game.h"
using namespace std;

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
  } else if(ai_mode == 3) {
    play_td0(board);
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
void td_state::set_game_state(state input_state){
  game_state = input_state;
}
void td_state::set_gained_score(int score){
  gained_score = score;
}
void td_state::set_chosed_direction(int direction){
  chosed_direction = direction;
}
state td_state::get_game_state(){
  return game_state;
}
int td_state::get_gained_score(){
  return gained_score;
}
int td_state::get_chosed_direction(){
  return chosed_direction;
}

void state_logger::clear_states(){
  const int logger_size = 625;
  for(int i=0;i<4;i++){
    for(int j=0;j<logger_size;j++){
      for(int k=0;k<logger_size;k++){
        for(int l=0;l<logger_size;l++){
          for(int m=0;m<logger_size;m++){
            states[i][j][k][l][m] = 0;
          }
        }
      }
    }
  }
}

void state_logger::update_state(state input_state,int direction,int scored,double learning_rate){
  vector<int> hashed_state = input_state.get_hash();
  int &cur_state = states[direction][hashed_state[0]][hashed_state[1]][hashed_state[2]][hashed_state[3]];
  cur_state += (scored-cur_state) * learning_rate;
}

int state_logger::best_direction(state current_state){
  vector<int> hashed_state = current_state.get_hash();
  int ret = rand()%4;

  for(int i=0;i<4;i++){
    if(states[i][hashed_state[0]][hashed_state[1]][hashed_state[2]][hashed_state[3]] > states[ret][hashed_state[0]][hashed_state[1]][hashed_state[2]][hashed_state[3]])ret = i;
  }

  return ret;
}
void ai::play_td0(ui_game &board){
  state_logger logger;
  for(int i=0;i<1000;i++){
    vector<td_state> training_data;
    while(!board.check_game_over()){
      vector<int> now = board.get_board();
      td_state now_td_state;
      state now_state(now);
      fake_game.set_board(now);
      int best_choice = logger.best_direction(now);
      now_td_state.set_game_state(now_state);
      now_td_state.set_gained_score(fake_game.move_cells(best_choice));
      now_td_state.set_chosed_direction(best_choice);
      board.play_by_direction(best_choice);
    }
    int score_total = 0;
    for(auto it=training_data.rbegin();it!=training_data.rend();it++){
      score_total += (*it).get_gained_score();
      logger.update_state((*it).get_game_state(),(*it).get_chosed_direction(),score_total,0.2);
    }
  }
}
