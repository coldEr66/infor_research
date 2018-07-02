#pragma once
#include "game.h"
#include "ui_game.h"
class state{
private:
  vector<int> row;
public:
  state();
  state(vector<int> &input);
  vector<int> get_vector();
  vector<int> get_hash();
  void set_hash(const vector<int> &v);
};
class td_state{
private:
  state game_state;
  int gained_score;
public:
  void set_game_state(state input_state);
  void set_gained_score(int score);
  state get_game_state();
  int get_gained_score;
};
class state_loger{
private:
  td_state states[4][625][625][625][625];
public:
  void clear_states();
  void update_state(state input_state,int direction,int scored,int learning_rate);
  int best_direction(state current_state);
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
