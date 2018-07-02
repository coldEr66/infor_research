#include <bits/stdc++.h>
using namespace std;

vector<int> row;

void gt(vector<int> &v){
  row.clear();
  int mx = __lg(16)+1;
  for(int i=0;i<4;i++){
    int hash_val = 0;
    for(int j=0;j<4;j++){
      int pw = 1;
      for(int k=0;k<j;k++) pw*=mx;
      if(v[i*4+j]==0) continue;
      else if(v[i*4+j]<=16) hash_val+=__lg(v[i*4+j])*pw;
      else if(v[i*4+j]>16) hash_val+=__lg(16)*pw;
    }
    cout<<hash_val<<endl;
    row.push_back(hash_val);
  }
}
vector<int> rt(){
  vector<int> ret;
  int mx = __lg(16)+1;
  for(int i=3;i>=0;i--){
    int tmp_row = row[i];
    int pw = 1;
    for(int j=0;j<3;j++) pw*=mx;
    while(tmp_row){
      int lgtmp_cell = tmp_row/pw;
      int tmp_cell = 1;
      for(int k=0;k<lgtmp_cell;k++) tmp_cell*=2;
      tmp_row -= lgtmp_cell*pw;
      pw/=mx;
      ret.push_back(tmp_cell);
    }
  }
  reverse(ret.begin(),ret.end());
  return ret;
}
int main(){
  vector<int> v;
  for(int i=0;i<16;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  gt(v);
  cout<<"HI"<<endl;
  vector<int> ans = rt();
  cout<<"hello"<<endl;
  for(int i=0;i<(int)v.size();i++) cout<<v[i]<<' ';
  cout<<endl;
  for(int i=0;i<(int)ans.size();i++) cout<<ans[i]<<' ';
  cout<<endl;
}
