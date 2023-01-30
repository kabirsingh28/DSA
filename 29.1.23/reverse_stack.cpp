#include<bits/stdc++.h>
using namespace std;
#include <stack>

void reverse_stack(stack<int> &s1,stack<int> &s2){
     if(s1.empty() || s1.size()==1){
        return;
     }
     int x = s1.top();
     s1.pop();
     reverse_stack(s1,s2);
     while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
     }
     s1.push(x);
     while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
     }

    
}

int main()
{   
    stack<int> s1,s2;
    int n;
    cin>>n;
    int data;
    while(n--){
        cin>>data;
        s1.push(data);
    }
    
    reverse_stack(s1,s2);

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }

    return 0;
}