#pragma once
#include <map>
#include "game.h"
class ui_game: public game{
private:
  int maxcell;
  int best;
  std::map<char,int> keymap;
  void print_game_over();//print game over hint
  void generate_keymap();
public:
  void init_data();
  void game_loop();
  void start_new_ui_game();
  void start_new_ai_game();
  void play_by_direction(int direction);
  bool ask_restart();
  void restart_game();
  void print_slug();
  void print_board();
};
