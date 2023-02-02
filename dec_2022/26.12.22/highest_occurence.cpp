#include<bits/stdc++.h>
using namespace std;

char largest(int a[]){
    int L=a[97],t=0;
    for(int i='a'; i<='z'; i++){
     if(a[i]>L){
        L=a[i];
        t=i;
     }
    }
    return t;
    
}

char highest_occurence(string &s){
    int t;
    int a[256]={0};
    for(int i = 0; i < s.length();i++){
         t=s[i];
         a[t]++;         
    }
    
    return largest(a);

}

int main(){
   string s;
   cin>>s;
   cout<<highest_occurence(s);
}