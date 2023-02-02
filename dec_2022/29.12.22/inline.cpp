#include<bits/stdc++.h>
using namespace std;

inline int max(int *x, int *y) {
    return *x>*y?*x:*y;
}

int main()
{   
    int * p = new int;
    int * q = new int;
    cin>>*p>>*q;
    cout<<max(p,q);

    delete p;
    delete q;

    return 0;
}