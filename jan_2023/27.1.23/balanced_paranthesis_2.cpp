#include<bits/stdc++.h>
using namespace std;
#include <stack>

int main()
{   string str;
    cin>>str;

    stack<char> s;
    int i;
    for(i=0; i<str.length();){
        if(str[i]=='[' || str[i]=='{' || str[i]=='('){
            s.push(str[i]);
            i++;
        }
        else if(s.top()=='(' && str[i]==')' || s.top()=='{' && str[i]=='}' || s.top()=='[' && str[i]==']'){
            s.pop();
            i++;
        }
        else{
            i++;
        }
    }    

    if(s.empty()) cout<<"1";
    else cout<<"0";
    
    
    return 0;
}