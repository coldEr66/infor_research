#include <bits/stdc++.h>
#include "game.h"
#include "ui_game.h"
using namespace std;

int main(){
  int game_mode;
  cout<<"Welcome to 2048 project!!! Please chose a mode to play..."<<endl;
  cout<<"(0:DIY/1:AI)"<<endl;
  cin>>game_mode;
  bool mode_chosed = false;
  while(!mode_chosed){
    if(game_mode == 0) {
      mode_chosed = true;
      ui_game root;
      root.start_new_ui_game();
    } else if(game_mode == 1) {

    } else {

    }

  }
  return 0;
}
