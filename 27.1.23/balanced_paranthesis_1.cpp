#include<bits/stdc++.h>
using namespace std;
#include <stack>

int main()
{   string str;
    cin>>str;

    stack<char> s;
    int i;
    for(i=0; i<str.length(); i++){
        if(str[i]=='[' || str[i]=='{' || str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            break;
        }
    }

    for(int j=i; j<str.length(); j++){
        if(s.top()=='(' && str[j]==')' || s.top()=='{' && str[j]=='}' || s.top()=='[' && str[j]==']'){
           s.pop();
        }
    }

    if(s.empty()) cout<<"1";
    else cout<<"0";
    
    
    return 0;
}