#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=28;
    cout<<&i<<endl;

    int * p = &i;
    cout<<p<<endl;

    cout<<*p<<endl;

    float f = 1.8;
    double d = 45612.3;

    float * fp = &f;
    double * dp = &d;

    cout<<fp<<" "<<dp<<endl;
}
