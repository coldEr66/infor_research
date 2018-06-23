#pragma once
#include "game.h"
#include "ui_game.h"
class ai{
private:
  int ai_mode;
  game fake_game;
  /*
  0: greedy highest score
  */
  void init_fake_game();
  void play_greedy(ui_game &board);
  void play_randomly(ui_game &board);
public:
  ai();
  ai(int mode);
  void auto_play(ui_game &board);
};
