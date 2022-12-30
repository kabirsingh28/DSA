#include<bits/stdc++.h>
using namespace std;

int last_index(int p[], int size , int x, int i=0)
{   int a;
    if(p[0]==x) a=i;
    if(size==1) return a;
    last_index(p+1,size-1,x,i+1);
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
    cout<<last_index(p,n,x);
    delete p;
    return 0;
}