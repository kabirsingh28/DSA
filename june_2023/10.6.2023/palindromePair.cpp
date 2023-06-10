#include<bits/stdc++.h>
using namespace std;
#include "Trie.h"

bool palindrome(vector<string>& words){
    Trie t;
    for(int i=0; i<words.size(); i++){
        t.insertWord(words[i]);
    }
    for(int i=0; i<words.size(); i++){
        string w = words[i];
        reverse(words[i].begin(),words[i].end());
        if(words[i]==w || t.searchWord(words[i])) return true;
        else return false;
    }
}


int main()
{   int n;
    cin>>n;
    vector<string> words;
    while(n--){
    string word;
    cin>>word;
    words.push_back(word);
   }

    if(palindrome(words)) cout<<"true";
    else cout<<"false";

    return 0;
}