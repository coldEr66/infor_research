#include <iostream>
#include <algorithm>
using namespace std;

string sw(int n){
  string ret = "";
  while(n){
    ret += (n % 10) + '0';
    n /= 10;
  }
  reverse(ret.begin(),ret.end());
  int len = 6 , l = (len - ret.size()) / 2;
  for(int i=0;i<l;i++) ret = ' ' + ret;
  for(int i=0;i<len-l-ret.size()+1;i++) ret += ' ';
  return ret;
}

int main()
{
  int n;
  cin>>n;
  string num = sw(n);
  cout << "\033[1;31;47m" << num << "\033[0m\n";
}
