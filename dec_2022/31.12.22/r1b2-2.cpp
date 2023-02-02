#include<bits/stdc++.h>
using namespace std;

string removeX(string s){
    if(s.size()==0) return "";
    if(s[0]=='x') return removeX(s.substr(1));
    return s[0]+ removeX(s.substr(1));
}

int main()
{   string s;
    cin>>s;
    cout<<removeX(s);

    return 0;
}