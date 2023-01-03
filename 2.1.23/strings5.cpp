#include<bits/stdc++.h>
using namespace std;

string table(int k){
    switch (k)
    {
    case 2:
        return "abc";
        break;
    case 3:
        return "def";
        break;
    case 4:
        return "ghi";
        break;
    case 5:
        return "jkl";
        break;
    case 6:
        return "mno";
        break;
    case 7:
        return "pqrs";
        break;
    case 8:
        return "tuv";
        break;
    case 9:
        return "wxyz";
        break;
    }
}

void print_keypad(int n, string output){
    if(n==0){
        cout<<output<<endl;
        return;
    }
    string s = table(n%10);
    for(int i=0; i<s.size(); i++){
     print_keypad(n/10, s[i]+output );
    }

}

int main()
{   int n;
    cin>>n;
    string output = "";
    print_keypad(n,output);
    return 0;
}