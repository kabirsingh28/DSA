#include<bits/stdc++.h>
using namespace std;

void sort_string(string &str){
    sort(str.begin(),str.end());
}

int main(){
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;
    sort_string(str1);
    sort_string(str2);
    if(str1.compare(str2)==0){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}