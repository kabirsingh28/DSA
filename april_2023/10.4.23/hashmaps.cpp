#include<bits/stdc++.h>
using namespace std;

int max_freq(string &str){
    int arr[256] = {0};
    for(int i=0; i<str.length(); i++){
        arr[str[i]]++;
    }
    int L = 0;
    int i = 0;
    while(i<str.length()){
    if(arr[str[i]]>L){
        L=arr[str[i]];
    }
    i++;
    }
    return L;
}

int main()
{   string str;
    cin>>str;
    cout<<max_freq(str);
    return 0;
}