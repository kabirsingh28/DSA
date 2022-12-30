#include<bits/stdc++.h>
using namespace std;

double geo_sum(int k){
    if(k==0) return 1;
    return pow(0.5,k)+geo_sum(k-1);
}

int main()
{   int k;
    cin>>k;
    cout<<geo_sum(k);
    return 0;
}