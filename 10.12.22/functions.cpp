#include <bits/stdc++.h>
using namespace std;
void getarrvalue(char arr[], int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void printrevarrvalue(char arr[], int n){
    for(int i=n-1; i>=0; i--){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n=5;
    char arr[n];
    getarrvalue(arr,n);
    printrevarrvalue(arr,n);
    
}