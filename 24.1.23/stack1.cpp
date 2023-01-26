#include<bits/stdc++.h>
using namespace std;
#include "dynamic_stack.cpp"

int main()
{   Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); //stack of double size is constructed here

    cout<<s.top()<<endl; //60
    cout<<s.pop()<<endl; //60
    cout<<s.pop()<<endl; //50
    cout<<s.pop()<<endl; //40
    cout<<s.pop()<<endl; //30

    cout<<s.size()<<endl; //2
    cout<<s.isEmpty()<<endl; //0

    return 0;
}