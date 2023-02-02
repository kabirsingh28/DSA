#include<bits/stdc++.h>
using namespace std;
#include <stack> 

int main()
{    stack<char> s;
     string str;
     cin>>str;

     if(str.length()%2!=0){
        cout<<"-1";
     }
     else{
     for(int i=0; i<str.length(); i++){
        if(str[i]=='{'){
            s.push(str[i]);
        }
        else{
            if(s.empty()){
            s.push(str[i]);
            }
            else if(!s.empty()&&s.top()=='{'){
            s.pop();
            }
            else if(!s.empty()&&s.top()=='}'){
            s.push(str[i]);    
            }
        }

        }
        int c1,c2,count=0;
     while(!s.empty()){
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();
        if(c1==c2){
         count+=1;
        }
        else{
         count+=2;
        }
     }

     cout<<count;
     }
    
    return 0;
}