#include<bits/stdc++.h>
using namespace std;

void inc(int * p){
    (*p)++;
}

int main(){
    int i=10;
    int * p =&i;
    cout<<p<<endl;
    inc(p);
    cout<<i<<endl;
}