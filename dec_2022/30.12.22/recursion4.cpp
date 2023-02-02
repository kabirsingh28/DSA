#include<bits/stdc++.h>
using namespace std;

int digits(int d){
   
    if(d == 0){
        return 0;
    }
    return 1+digits(d/10);
}

int main()
{   int n;
    cin >> n;
    cout<<digits(n);
    return 0;
}