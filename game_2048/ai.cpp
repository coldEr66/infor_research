#include "ai.h"
#include "game.h"
using namespace std;
ai::ai(){
  ai_mode = 0;
}
ai::ai(int mode){
  ai_mode = mode;
}
ai::auto_play(game &board){
  if(ai_mode == 0){
    play_greedy(board);
  }
}
ai::play_greedy(game &board){
  
}
