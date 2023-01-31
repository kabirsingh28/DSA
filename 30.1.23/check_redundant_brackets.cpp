#include<bits/stdc++.h>
using namespace std;
#include <stack>

int main()
{   
    stack<char> s;
    int i=0,flag=0;
    string str;
    cin>>str;
    while(i!=str.length()){
        int count=0;
        for(;str[i]!=')';i++){
            s.push(str[i]);
        }
        i++;
        while(s.top()!='('){
            count++;
            s.pop();
        }
        s.pop();
        if(count==0||count==1){
            cout<<"true";
            flag=1;
            break;
        }
    }
    if(flag==0) cout<<"false";

    return 0;
}