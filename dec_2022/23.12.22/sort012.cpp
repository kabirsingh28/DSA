#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[],int n){
    int j=0,k=n-1,i=0;
    while(i<k){
        switch (arr[i]){
        {
        case 0:
            swap(arr[i],arr[j]);
            i++;
            j++;
            break;
        
        case 2:
            swap(arr[i],arr[k]);
            k--;
            break;
        
        case 1:
            i++;
            break;
        }
    }
    
}
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort012(arr,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}