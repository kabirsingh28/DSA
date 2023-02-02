#include<bits/stdc++.h>
using namespace std;
#include <stack>

int main()
{   
    stack<char> s;
    string str;
    bool isredundant;
    cin>>str;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='(' || str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            s.push(str[i]);
        }
        else if(str[i]==')'){
               isredundant = true; //vese we have assumed ke isredundant = true
            while(s.top()!='('){
            if(s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/'){
                 isredundant = false; //isredundant is set to false isf '(+)' such situation arises, i.e brackets de vich koi signs aa jaan
            }
            s.pop();
        }
        s.pop();
        if(isredundant){
             cout<<"true";
             break;
             }
        }
    }

    if(!isredundant){
        cout<<"false";
    }

    
    return 0;
}