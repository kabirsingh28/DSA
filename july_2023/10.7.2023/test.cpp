#include<bits/stdc++.h>
using namespace std;
#include "DisjointSet.h"
int main()
{   DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);

    if(ds.findUPar(3)==ds.findUPar(7)) cout<<"same";
    else cout<<"not same"<<endl;

    ds.UnionBySize(3,7);

    if(ds.findUPar(3)==ds.findUPar(7)) cout<<"same";
    else cout<<"not same";

    return 0;
}