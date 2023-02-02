#include<bits/stdc++.h>
using namespace std;

string is_sorted(int p[], int size){
    if(size==0||size==1) return "sorted";
    if(p[size-2]>p[size-1]) return "not sorted";
    else return is_sorted(p, size-1);    
}

int main()
{   int *p = new int[10];
    for (int i = 0; i < 10; i++){
        cin >> p[i];
    }
    cout<<is_sorted(p,10);
    delete p;
    return 0;
}