#include<bits/stdc++.h>
using namespace std;

int digisum(int a){
    if(a/10==0) return a;
    return a%10 + digisum(a/10);
}

int main()
{   
    int * p =new int;
    cin>>*p;
    cout<<digisum(*p);
    delete p;
    return 0;
}