#pragma once
#include <map>
#include <vector>
class game{
protected:
  int cell[4][4];
  int score;
  void clear_cell();
public:
  void set_board(std::vector<int> input);
  bool check_game_over();
  int move_cells(int direction);
  void generate_random_cell();
  std::vector<int> get_board();
};
