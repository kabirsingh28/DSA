#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicate(int* arr,int size){
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0; i<size; i++){
        if(seen.count(arr[i])==0){
           seen[arr[i]] = true;
           output.push_back(arr[i]);
        }
    }
    return output;
}

int main()
{   int arr[] = {1,8,5,9,6,7,5,3,9,4,1,6,1,2,3,4,5,6,7,8,9};
    vector<int> output = removeDuplicate(arr,21);
    for(int i=0; i<output.size(); i++){
        cout<<output[i]<<" ";
    }
    return 0;
}   