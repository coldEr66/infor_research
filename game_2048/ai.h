#pragma once
#include "game.h"
#include "ui_game.h"
class state{
private:
  vector<int> row;
public:
  vector<int> get_vector();
  vector<int> get_hash();
  void set_hash(const vector<int> &v);
};
class td_state{
private:
  state game_state;
  int chosed_direction;
  int expected_score;
public:
  void set_game_state(state input_state);
  void set_gained_score(int score);
  void set_chosed_direction(int direction);
  state get_game_state();
  int get_chosed_direction;
  int get_gained_score;

};
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
  void play_cycle(ui_game &board);
  void play_td0(ui_game &board);
public:
  ai();
  ai(int mode);
  void auto_play(ui_game &board);
};
