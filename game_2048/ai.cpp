#include <iostream>
#include <cassert>
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
  }
}

void ai::play_randomly(ui_game &board){
  while(!board.check_game_over()){
    board.play_by_direction(rand()%4);
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
