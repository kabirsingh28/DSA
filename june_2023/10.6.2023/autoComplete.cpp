#include<bits/stdc++.h>
using namespace std;
#include "Trie.h"

void autoComplete(vector<string>& words,string w){
    Trie t;
    for(int i=0; i<words.size(); i++){
        t.insertWord(words[i]);
    }
    
    TrieNode * node = t.findWord(w);
    if(node!=NULL) t.allPossibleWords(node,w);
}

int main()
{
    int n;
    cin>>n;
    vector<string> words;
    while(n--){
    string word;
    cin>>word;
    words.push_back(word);
    }

    string w;
    cin>>w;

    autoComplete(words,w);

    return 0;
}