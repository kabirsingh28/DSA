#include<bits/stdc++.h>
using namespace std;

int check_unique(int arr[], int size){
    int flag=0;
    for(int j=0; j<size; j++){
        int i=0;
        for(; i<size; i++){
            if((arr[j]==arr[i]) && (j!=i)){
             break;
            }            
        }
        if(i==size){
            return arr[j];
        }
    }
 
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<check_unique(arr,size);
}