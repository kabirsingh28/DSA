#include<bits/stdc++.h>
using namespace std;

int multi(int a,int b){
    if(b==1) return a;
    return a+multi(a,b-1);
}

int main()
{   
    int a,b;
    cin>>a;
    cin>>b;
    cout<<"mutiplication: "<<multi(a,b);
    return 0;
}