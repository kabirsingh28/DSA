#include<bits/stdc++.h>
using namespace std;

string remove_charachter(string input, char c){
  string output;
  for(int i = 0; i < input.length(); i++){
    if(input[i] != c){
        output.push_back(input[i]);
  }
}
  return output;
}

int main(){
    string input;
    cin>>input;
    char c;
    cin>>c;
    cout<<remove_charachter(input,c);
}