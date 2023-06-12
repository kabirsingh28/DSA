#include<bits/stdc++.h>
using namespace std;

int f(int i,int sum,int K,int arr[],vector<int>& ds){
    if(i==4){
    if(sum==K){
        // for(auto it : ds){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return 1;
    }
    else return 0;
    }
    sum+=arr[i];
    ds.push_back(arr[i]);
    int left = f(i+1,sum,K,arr,ds);
    sum-=arr[i];
    ds.pop_back();
    int right = f(i+1,sum,K,arr,ds);
    return left + right;
    // doing this only one sequence will be printed
}

int main()
{   vector<int> ds;
    int K = 3;
    int arr[] = {1,2,1,3};
    cout<<f(0,0,K,arr,ds);
    return 0;
}