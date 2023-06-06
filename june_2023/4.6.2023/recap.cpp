#include<bits/stdc++.h>
using namespace std;

vector<int> remove_duplicate(int *arr, int size){
       vector<int> output;
       unordered_map<int,bool> seen;
       for(int i=0; i<size; i++){
        if(seen.count(arr[i])>0){
            continue;
       }
       else{
        seen[arr[i]] = true;
        output.push_back(arr[i]);
       }
}
       return output; 
}


int max_freq(int *arr, int n){
    unordered_map<int,int> freq;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    int L=0;
    int T;
    for(int i=0; i<n; i++){
        if(L<freq[arr[i]]){
            L = freq[arr[i]];
            T = arr[i];
        }
    }
    return T;
}

vector<int> intersection(int* a,int* b,int n,int m){
       vector<int> output;
       unordered_map<int,int> freq;
       for(int i=0; i<n; i++){
        freq[a[i]]++;
       }
       for(int i=0; i<m; i++){
        if(freq.count(b[i])>0){
            output.push_back(b[i]);
        }
       }
       return output;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    int m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int j=0; j<m; j++){
        cin>>b[j];
    }
    vector<int> output = intersection(a,b,n,m);
    for(int i=0; i<output.size(); i++){
        cout<<output.at(i)<<" ";
    }
    }
    //   int n;
    //   cin>>n;
    //   int arr[n];
    //   for(int i=0; i<n; i++){
    //     cin>>arr[i];
    //   }
    //   cout<<max_freq(arr,n);
//    int arr[9] = {1,2,3,2,1,5,4,1,3};
//    vector<int> v = remove_duplicate(arr,9);
//    for(int i=0; i<v.size(); i++){
//     cout<<v.at(i)<<" ";
//    }
// {   string str;
//     cin>>str;
//     int arr[256] = {0};
//     for(int i=0; i<str.size(); i++){
//         arr[str[i]]++;
//     }

//     int L=0;
//     int i=0;
//     char c;
//     while(i<str.size()){
//         if(L<arr[str[i]]){
//             L= arr[str[i]];
//             c= str[i];
//         }
//         i++;
//     }
//     cout<<c;
//    unordered_map<string,int> mymap;
//    pair<string,int> p("abc",1);
//    mymap.insert(p); // map accepts a pair

//    mymap["def"] = 2;

//    cout<<mymap["abc"]<<" "<<mymap["def"]<<"\n";
//    if(mymap.count("abc")){
//    cout<<"present";
//    }
//    mymap.erase("def");
//    cout<<mymap.size();

//     return 0;
}