#include <bits/stdc++.h>
using namespace std;

class game{

private:
  int cell[4][4] = {};
  int score = 0;
  int best = 0;
  map<char,int> keymap;

  void print_game_over(){ //print game over hint
    cout<<"GAME OVER!"<<endl;
  }

  void generate_keymap(){
    string keystr = "wdsa";
    for(int i=0;i<4;i++) keymap[keystr[i]] = i;
  }

public:

  void game_loop(){
    char c;
    while(cin>>c){
      move_cells(keymap[c]);
      if(check_game_over()){
        print_game_over();
        if(ask_restart()) start_new_game();
        else break;
      }
    }
  }

  void start_new_game(){

  }

  bool ask_restart(){

  }

  void restart_game(){

  }

  bool check_game_over(){ //return if the game's over
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(cell[i][j]==0) return false;
      }
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<3;j++){
        if(cell[i][j]==cell[i][j+1]) return false;
      }
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<3;j++){
        if(cell[j][i]==cell[j+1][i]) return false;
      }
    }
    return true;
  }

  void move_cells(int direction){ //move cells {0,1,2,3} = {up,right,down,left}

  }

  void print_slug(){
    cout<<"I'm a slug"<<endl;
  }

  void print_cell(){
    system("clear");
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        cout<<setw(6)<<cell[i][j];
      }
      cout<<endl;
    }
  }

  void generate_random_cell(){
    vector<pair<int,int> > available;
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
        if(cell[i][j]==0)available.push_back({i,j});

    int choice = rand() % int(available.size());
    cell[available[choice].first][available[choice].second] = (rand()%10?2:4);
    print_cell();
  }


};
int main(){
  game root;

  return 0;
}
