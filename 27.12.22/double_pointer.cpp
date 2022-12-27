#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=10;
    int * p = &i;
    int **q = &p;//double pointer
     cout<<q<<endl;
     cout<<&p<<endl;
     cout<<p<<endl;
     cout<<&i<<endl;
     cout<<*q<<endl;
     cout<<i<<endl;
     cout<<**q<<endl;
     cout<<*p<<endl;
}