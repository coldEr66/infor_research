#include <bits/stdc++.h>
using namespace std;

class game{

private:
  int cell[4][4] = {};
  int score = 0;
  int maxcell = 0;
  int best = 0;
  map<char,int> keymap;

  void print_game_over(){ //print game over hint
    cout<<"GAME OVER!"<<endl;
    cout<<"Score: "<<setw(8)<<score<<endl;
    cout<<"Maxcell: "<<setw(6)<<maxcell<<endl;
  }

  void generate_keymap(){
    string keystr = "wdsa";
    for(int i=0;i<4;i++) keymap[keystr[i]] = i;
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
    char c;
    while(cin>>c){
      if(keymap.find(c)==keymap.end()) {
        print_board();
        continue;
      }
      move_cells(keymap[c]);
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

  void start_new_game(){
    generate_keymap();
    print_board();
    game_loop();
  }

  bool ask_restart(){
    cout<<"Do you want to start a new game? (Y/n)"<<;
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

  void restart_game(){
    clear_cell();
    print_board();
    score = 0;
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
    if(direction == 0){ //up
      for(int j=0;j<4;j++){ //numbers of cols
        for(int i=1;i<4;i++){ //index of cell to move
          int k; //bottom most not empty cell
          for(k=i-1;k>=0;k--){
            if(cell[k][j] != 0)break;
          }
          if(cell[i][j] == cell[k][j]){
            cell[k][j] += cell[i][j];
            score += cell[k][j];
            cell[i][j] = 0;
          } else {
            int tmp = cell[i][j];
            cell[i][j] = 0;
            cell[k+1][j] = tmp;
          }
        }
      }
    } else if(direction == 1) { //right
      for(int i=0;i<4;i++){ //numbers of rows
        for(int j=2;j>=0;j--){ //index of cell to move
          int k; //left most not empty cell
          for(k=j+1;k<4;k++){
            if(cell[i][k] != 0)break;
          }
          if(cell[i][j] == cell[i][k]){
            cell[i][k] += cell[i][j];
            score += cell[i][k];
            cell[i][j] = 0;
          } else {
            int tmp = cell[i][j];
            cell[i][j] = 0;
            cell[i][k-1] = tmp;
          }
        }
      }
    } else if(direction == 2) {
      for(int j=0;j<4;j++){ //numbers of cols
        for(int i=2;i>=0;i--){ //index of cell to move
          int k; //top most not empty cell
          for(k=i+1;k<4;k++){
            if(cell[k][j] != 0)break;
          }
          if(cell[i][j] == cell[k][j]){
            cell[k][j] += cell[i][j];
            score += cell[k][j];
            cell[i][j] = 0;
          } else {
            int tmp = cell[i][j];
            cell[i][j] = 0;
            cell[k-1][j] = tmp;
          }
        }
      }
    } else if(direction == 3) { //left
      for(int i=0;i<4;i++){ //numbers of rows
        for(int j=1;j<4;j++){ //index of cell to move
          int k; //right most not empty cell
          for(k=j-1;k>=0;k--){
            if(cell[i][k] != 0)break;
          }
          if(cell[i][j] == cell[i][k]){
            cell[i][k] += cell[i][j];
            score += cell[i][k];
            cell[i][j] = 0;
          } else {
            int tmp = cell[i][j];
            cell[i][j] = 0;
            cell[i][k+1] = tmp;
          }
        }
      }
    }
    best = max(best,score);
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        maxcell = max(maxcell,cell[i][j]); //max value of all cells
      }
    }
  }

  void print_slug(){
    cout<<"I'm a slug"<<endl;
  }

  void print_board(){
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

  void generate_random_cell(){
    vector<pair<int,int> > available;
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
        if(cell[i][j]==0)available.push_back({i,j});

    if(available.empty())return;
    int choice = rand() % int(available.size());
    cell[available[choice].first][available[choice].second] = (rand()%10?2:4);
    return;
  }


};
int main(){
  game root;
  root.start_new_game();
  return 0;
}
