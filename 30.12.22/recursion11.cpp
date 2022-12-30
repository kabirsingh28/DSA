#include<bits/stdc++.h>
using namespace std;

int first_index(int p[], int size , int x, int i=0)
{
   if(p[0]==x) return i;
   if(size==1) return -1;
   first_index(p+1, size-1, x, i+1);
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
    cout<<first_index(p,n,x);
    delete p;
    return 0;
}