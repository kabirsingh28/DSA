#include<bits/stdc++.h>
using namespace std;

void f(int i,int n,vector<int>& ds,int arr[]){
    if(i==n){
        for(auto it : ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    //pick the particular index into subsequence
    ds.push_back(arr[i]);
    f(i+1,n,ds,arr);
    //not pick the particular index into subsequence
    ds.pop_back();
    f(i+1,n,ds,arr);
}

int main()
{   int n=3;
    vector<int> ds;
    int arr[] = {3,1,2};
    f(0,n,ds,arr);
    return 0;
}