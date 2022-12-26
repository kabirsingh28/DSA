#include<bits/stdc++.h>
using namespace std;


void compress(string &s){
  {   int flag,x;
      string output; 
      for(int i=0; i<s.size();){
        output+=s[i];
        int flag=0;
      for(int j=0; j<s.size();j++){
          if(s[j]==s[i]){
              flag++;
          }
         
      } 
        if(flag!=1){
            x=flag;
        output+=to_string(x);
        }
        i=flag+i;
        
      }
      cout<<output<<endl;
}
}

int main(){
    string str;
    int t;
    cin>>t;
    while(t--){
    cin>>str;
    compress(str);
    
}
}