#include<bits/stdc++.h>
using namespace std;
#include "Trie.h"

bool patternMatching(vector<string>& words,string p){
    Trie t;
    for(int i=0; i<words.size(); i++){
        for(int j=0; j<words[i].size(); j++){
         t.insertWord(words[i].substr(j));
        }
    }
    return t.searchWord(p);
}

int main()
{  int n;
   cin>>n;
   vector<string> words;
   while(n--){
    string word;
    cin>>word;
    words.push_back(word);
   }
   string p;
   cin>>p;

   if(patternMatching(words,p)) cout<<"true";
   else cout<<"false";

   return 0;
}