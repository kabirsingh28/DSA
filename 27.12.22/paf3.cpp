#include<bits/stdc++.h>
using namespace std;

int sum(int *a,int s){
    cout<<sizeof(a)<<endl;
    int t=0;
    for(int i=0;i<s;++i){
        t+=a[i];
    }
    return t;
}

int main(){
    int a[]={1,2,3,4,5,6,7};
    cout<<sizeof(a)<<endl;
    cout<<sum(a+3,2);
}