#include<bits/stdc++.h>
using namespace std;

void triplet(int arr[], int n, int sum){
    int flag = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1;;){
        for(int k = j+1; k < n; k++){
           if(arr[i]+arr[j]+arr[k] == sum){
            flag++;
           }
        }
  }

}
cout<<flag;
}

int main(){
   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    triplet(arr,n,sum);

    }
