#include<bits/stdc++.h>
using namespace std;
int second_largest(int arr[],int n){
    int L=arr[0],S;
    for(int i=1; i<n; i++){        
        if(arr[i]>L){
            S=L;
            L=arr[i];
        }
    }
    return S;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<second_largest(arr,n);
}