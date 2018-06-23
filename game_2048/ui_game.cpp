#include <bits/stdc++.h>
using namespace std;
#include "ui_game.h"

void ui_game::print_game_over(){ //print game over hint
  cout<<"GAME OVER!"<<endl;
  cout<<"Score: "<<setw(8)<<score<<endl;
  cout<<"Maxcell: "<<setw(6)<<maxcell<<endl;
}

void ui_game::generate_keymap(){
  string keystr = "wdsa";
  for(int i=0;i<4;i++) keymap[keystr[i]] = i;
}

void ui_game::game_loop(){
  char c;
  while(cin>>c){
    if(keymap.find(c)==keymap.end()) {
      print_board();
      continue;
    }
    score += move_cells(keymap[c]);
    best = max(best,score);
    if(check_game_over()){
      print_game_over();
      if(ask_restart()) restart_game();
      else {
        cout<<"Farewell!"<<endl;
        return;
      }
    }
    generate_random_cell();
    print_board();
  }
}

void ui_game::init_data(){
  maxcell = 0;
  best = 0;
}
void ui_game::start_new_ui_game(){
  init_data();
  clear_cell();
  generate_keymap();
  print_board();
  game_loop();
}

bool ui_game::ask_restart(){
  cout<<"Do you want to start a new game? (Y/n)";
  string res;
  cin>>res;
  while(1){
    if(res[0] == 'Y' || res[0] == 'y'){
      return true;
    } else if(res[0] == 'N' || res[0] == 'n'){
      return false;
    } else {
      cout<<"Do you want to start a new game? (Y/n)"<<endl;
      cin>>res;
    }
  }
}

void ui_game::restart_game(){
  clear_cell();
  print_board();
  score = 0;
}

void ui_game::print_slug(){
  cout<<"I'm a slug"<<endl;
}

void ui_game::print_board(){
  system("clear");
  cout<<"Score:"<<setw(6)<<score<<" Best:"<<setw(6)<<best<<endl;
  cout<<' ';
  for(int i=0;i<23;i++) cout<<'_';
  cout<<endl;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cout<<'|';
      cout<<setfill(' ')<<setw(3)<<cell[i][j]<<setw(3);
    }
    cout<<'|'<<endl;
    cout<<' ';
    for(int j=0;j<23;j++) cout<<'_';
    cout<<endl;
  }

}
