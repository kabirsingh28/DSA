#include<bits/stdc++.h>
using namespace std;

int smallest(int arr[],int start, int n){
    int t=start;
   for(int i=start+1; i<n; i++){
    if(arr[t]>arr[i]){
        t=i;
    }
   }
   return t;
}


int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
    cin >> arr[i];
    }
    for(int i=0;i<n-1;i++){
     int d,s=smallest(arr,i,n);
     d=arr[i];
     arr[i]=arr[s];
     arr[s]=d;
    }
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
    
}