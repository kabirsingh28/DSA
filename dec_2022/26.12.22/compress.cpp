#include<bits/stdc++.h>
using namespace std;

string compress(string &s){
    string output = "";
    int flag,j;
    for(int i=0; i<s.size(); i++){
        flag=0;
        for(j=i;j<s.size();j++){
            if(s[j]==s[i]){
                flag++;
            }
            else{
                break;
            }
        }
        if(flag!=1){
            output+=s[i]+to_string(flag);
        }
        else{
            output+=s[i];
        }
        i=j-1;
    }
    return output;
}
 

int main(){
    string str;
    int t;
    cin>>t;
    while(t--){
    cin>>str;
    cout<<compress(str);
    }
}