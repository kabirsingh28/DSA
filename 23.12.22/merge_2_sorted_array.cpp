#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr1[n];

    for(int i=0;i<n;i++){
    cin >> arr1[i];
    }

    int m;
    cin >> m;
    int arr2[m];

    for(int i=0;i<m;i++){
    cin >> arr2[i];
    }
    int arr3[m+n];
    int i=0;
    int j=0;
    int k=0;
    for(;(i<n) && (j<m);k++){
      if(arr1[i]<arr2[j]){
        arr3[k]=arr1[i];
        i++;
      }
      else{
        arr3[k]=arr2[j];
        j++;
      }
    }
    
    while(i<n){
        arr3[k++]=arr1[i++];
    }
     
    while(j<m){
        arr3[k++]=arr2[j++];
    }
    


     for(int i=0;i<m+n;i++){
    cout << arr3[i]<<" ";
    }

}