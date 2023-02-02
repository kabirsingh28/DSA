#include<bits/stdc++.h>
using namespace std;

string replacePI(string s){
    if(s.length()==0||s.length()==1) return s;
    if(s[0]=='p' && s[1]=='i') return "3.14" + replacePI(s.substr(2));
    else return s[0] + replacePI(s.substr(1));


}

int main()
{   string s;
    cin >> s;
    cout<<replacePI(s);
    return 0;
}