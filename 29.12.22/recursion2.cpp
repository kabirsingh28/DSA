#include<bits/stdc++.h>
using namespace std;

int powerfun(int x, int n){
    if(n==1){
        return x;
    }
    else{
        return x * powerfun(x,n-1);
    }
}

int main()
{   int x,n;
    cout<<"x^n:\n"<<"x = ";
    cin >> x;
    cout<<"n = ";
    cin >> n;
    cout<<"ans: "<<powerfun(x,n)<<endl;
    return 0;
}