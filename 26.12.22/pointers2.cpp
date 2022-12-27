#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=28;
    int * p = &i;

    i=28;
    *p=32;
    (*p)++;
    cout<<&i<<"";
    int * q = p;
    cout<<q<<"\n"<<*q;
}