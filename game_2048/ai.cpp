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
void ai::auto_play(game &board){
  if(ai_mode == 0){
    play_greedy(board);
  }
}
void ai::play_greedy(game &board){
  while(!board.check_game_over()){
    vector<int> now = board.get_board();
    int best = 0;
    for(int i=0;i<4;i++){
      if(fake_game.move_cells(i)>best)best = i;
      fake_game.set_board(now);
    }
    board.move_cells(best);
  }
}
