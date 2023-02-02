#include<bits/stdc++.h>
using namespace std;

void all_index(int p[], int size , int x, int i=0)
{
    if(p[0]==x) cout<<i<<" ";
    if(size==1) return;
    all_index(p+1,size-1,x,i+1);
}

int main()
{   
    int n;
    cin>>n;
    int *p = new int[n];
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    int x;
    cin>>x;
    all_index(p,n,x);
    delete p;
    return 0;
}