#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
    cin >> arr[i];
    }

    int x;
    cout<<"ki labna?"<<endl;
    cin >> x;
    int start = 0;
    int end = n-1;
    int mid;
     int flag = 0;
    while(start < end){
       
        mid = (start + end)/2;
        if(arr[mid]==x){
            cout<<"element found at "<<mid<<endl;
            flag++;
            break;
        }
        else if(arr[mid]<x){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if(!flag){
        cout<<"-1";
    }

}