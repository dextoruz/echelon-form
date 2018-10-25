#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>

// #define size 10

using namespace std;


void fra(){
  cout<<"Enter fraction: ";
  int fl = 0;
  string str = "", num="", dem="1";
  cin>>str;
  for(int i = 0; i < str.length(); i++){
    if(str[i] >= '0' && str[i] <= '9' || str[i] == '/'){
      if(str[i] == '/'){
        dem ="";
        fl = 1;
        continue;
      }
      if(fl == 0 ){
        num += str[i];
      }
      if(fl == 1){
        dem += str[i];
      }
    }
    else{
      // cout<<str[i]<<endl;
      cout<<"wrong attempt\n";
      _Exit(EXIT_FAILURE);
    }
  }
  cout<<num<<endl;
  cout<<dem<<endl;
  int x = 0, y = 0;
  x = stoi(num);
  y = stoi(dem);
  cout<<x<<'/'<<y<<endl;

  return;
}

int main(int argc, char const *argv[]) {

  // string str = "12/34";
  // for(int i = 0; i<5; i++){
  //   if(str[i] >= '0' && str[i] <= '9' && str[i] == '/'){
  //     cout<<str[i];
  //   }
  // }
  fra();

  return 0;
}
