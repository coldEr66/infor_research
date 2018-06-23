#pragma once
#include "game.h"
class ai{
private:
  int ai_mode;
  game fake_game;
  /*
  0: greedy highest score
  */
  void init_fake_game();
  void play_greedy(game &board);
public:
  ai();
  ai(int mode);
  void auto_play(game &board);
};
