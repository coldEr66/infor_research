#pragma once
#include <map>
class game{
private:
  int cell[4][4];
  int score;
  int maxcell;
  int best;
  std::map<char,int> keymap;

  void print_game_over();//print game over hint
  void generate_keymap();
  void clear_cell();

public:
  void game_loop();
  void start_new_game();
  bool ask_restart();
  void restart_game();
  bool check_game_over();
  int move_cells(int direction);
  void print_slug();
  void print_board();
  void generate_random_cell();
};
