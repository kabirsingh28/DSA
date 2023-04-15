#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicate(int * arr, int size){
    vector<int> output;
    unordered_map<int,bool> doesExsist;

    for(int i=0; i<size; i++){
        if(doesExsist.count(arr[i])!=0){
            continue;
        }
        else{
            doesExsist[arr[i]] = true;
            output.push_back(arr[i]);
        }
    }
    return output;
}

int maxFreq(int * arr, int size){
    unordered_map<int,int> freq;
    int Largest_freq=0;
    int Max_freq_num=-1;
    for(int i=0; i<size; i++){
       if(freq.count(arr[i])==0){
         freq[arr[i]]=1;
       }
       else{
         freq[arr[i]]++;
       }

       if(freq[arr[i]]>Largest_freq){
        Largest_freq = freq[arr[i]];
        Max_freq_num = arr[i];
       }

    }
     
    return Max_freq_num;
    
}

int main()
{   int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    cout<<maxFreq(arr,size);
    // int arr[] = {1,8,5,9,6,7,5,3,9,4,1,6,1,2,3,4,5,6,7,8,9};
    // vector<int> output = removeDuplicate(arr,21);
    // for(int i=0; i<output.size(); i++){
    //     cout<<output[i]<<" ";
    // }
    return 0;
}   