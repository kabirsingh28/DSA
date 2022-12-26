#include<bits/stdc++.h>
using namespace std;

string remove_duplicate(string &str){
    int t=str[0];
    int k=1;
    for(int i=1; i<=str.size();i++){
        if(str[i]!=t){
         str[k]=str[i];
         t=str[i];
         k++;
        }
    }
    for(int i=k; i<=str.size();i++){
        str[i]='\0';
    }
    return str;
}

int main(){
    string str;
    cin>>str;
    cout<<remove_duplicate(str);
    

}