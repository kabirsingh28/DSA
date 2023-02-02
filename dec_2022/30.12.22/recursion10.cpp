#include<bits/stdc++.h>
using namespace std;

bool check(int p[], int size, int a){
     if(p[0]==a) return true; 
     if(size==1) return false;
     check(p+1,size-1,a);
}

int main()
{   
    int n;
    cin>>n;
    int *p = new int[n];
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    int a;
    cin>>a;
    cout<<check(p,n,a);
    delete p;
    return 0;
}