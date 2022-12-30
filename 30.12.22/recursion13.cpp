#include<bits/stdc++.h>
using namespace std;

int countz(int n, int i=0){
    if(n%10==0) i=i+1;
    if(n/10==0) return i;
    countz(n/10, i);
}

int main()
{   int n;
    cin>>n;
    cout<<countz(n);
    return 0;
}