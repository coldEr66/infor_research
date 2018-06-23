#include <bits/stdc++.h>
#include "game.h"
#include "ui_game.h"
#include "ai.h"
using namespace std;

int main(){
  int game_mode;
  cout<<"Welcome to 2048 project!!! Please chose a mode to play..."<<endl;
  cout<<"(0:DIY/1:Auto Play)"<<endl;
  cin>>game_mode;
  bool mode_chosed = false;
  ui_game root;
  while(!mode_chosed){
    if(game_mode == 0) {
      mode_chosed = true;
      root.start_new_ui_game();
    } else if(game_mode == 1) {
      mode_chosed = true;
      int auto_function = -1;
      while(!(auto_function >= 0 && auto_function < 3)){
        cout<<"Which auto play function do you want to try?"<<endl;
        cout<<"(0:greedy 1:randomly 2:cycle)"<<endl;
        cin>>auto_function;
      }
      ai ai_player(auto_function);
      ai_player.auto_play(root);
    } else {

    }

  }
  return 0;
}
