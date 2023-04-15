#include<bits/stdc++.h>
using namespace std;

vector<int> arryIS(int* arr1,int* arr2,int m,int n){
    vector<int> output;
    unordered_map<int,int> freq;
    for(int i=0; i<m; i++){
        freq[arr1[i]] = 1;
    }
    for(int i=0; i<n; i++){
        if(freq.count(arr2[i])>0){
            output.push_back(arr2[i]);
        }
    }
    return output;

}

int main()
{   int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        int arr1[m];
        for(int i=0; i<m; i++) cin>>arr1[i];
        int n;
        cin>>n;
        int arr2[n];
        for(int i=0; i<n; i++) cin>>arr2[i]; 
        vector<int> output = arryIS(arr1,arr2,m,n);
        for(int i=0; i<output.size(); i++) cout<<output[i]<<" "; 
        cout<<endl;
    }
    return 0;
}