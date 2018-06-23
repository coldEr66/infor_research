#pragma once
#include "game.h"
class ai{
private:
  int ai_mode;
  /*
  0: greedy highest score
  */
  void play_greedy(game &board){

  }
public:
  ai();
  ai(int mode);
  void auto_play(game &board);
};
