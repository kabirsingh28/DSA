#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
    cin >> arr[i];
    }

    for(int i=1;i<n;i++){
        int d=arr[i];
        int j;
    for(j=i-1;j>=0;j--){        
     if(d<arr[j]){
        arr[j+1]=arr[j];
     }
     else{
        break;
     }
    }
    arr[j+1]=d;

    }


    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
    
}