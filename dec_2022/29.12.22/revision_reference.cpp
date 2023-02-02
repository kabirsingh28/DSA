#include<bits/stdc++.h>
using namespace std;

void inc(int &x){ // x and a are name of same memory location
    x++;
}

int main()
{
   int a=3,b=4;
   inc(a);
   cout<<a;
    return 0;
}