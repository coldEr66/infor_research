#include <bits/stdc++.h>
using namespace std;

class game{

private:
  int cell[4][4] = {};
  int score = 0;
  int best = 0;

  void print_game_over(){ //print game over hint

  }

  void clear_cell(){
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        cell[i][j] = 0;
      }
    }
  }

public:

  void game_loop(){

  }

  void start_new_game(){

  }

  void ask_restart(){

  }

  void restart_game(){
    clear_cell();
    score = 0;
  }

  bool check_game_over(){ //return if the game's over

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
