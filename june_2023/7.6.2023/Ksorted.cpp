#include<bits/stdc++.h>
using namespace std;

void Ksorted(int a[],int n, int k){
    priority_queue<int> pq;
    int i=0;
    for(; i<k; i++){
        pq.push(a[i]);
    }
   for(int j=0; j<n; j++){
    a[j] = pq.top();
    pq.pop();
    if(i<n){
    pq.push(a[i]);
    i++;
    }
   }
}

int main()
{   int a[] = {10,12,6,7,9};
    int k=3;
    Ksorted(a,5,k);
    for(int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}