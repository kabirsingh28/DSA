#include<bits/stdc++.h>
using namespace std;

int sum(int p[], int size){
    if(size==1) return p[0];
    return p[0]+sum(p+1,size-1); 
}

int main()
{   
    int n;
    cin>>n;
    int *p = new int[n];
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    cout<<sum(p,n);
    delete p;
    return 0;
}