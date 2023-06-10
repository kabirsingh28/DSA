#include "TrieNode.h"
#include <string.h>

class Trie{
    public:

    TrieNode * root;
     

     Trie(){
        root = new TrieNode('\0');
     }
     
     void allPossibleWords(TrieNode* root,string word){
        string output = "";
        allPossibleWords(root,word,output);
     }

     void allPossibleWords(TrieNode* root,string word,string output){
        if(root->isTerminal){
            cout<<word+output<<endl;
        }

        for(int i=0; i<26; i++){
            if(root->children[i]!=NULL){
                TrieNode* child = root->children[i];
                output += child->data;
                allPossibleWords(child,word,output);
            }
        }
        return;
     }

     TrieNode* findWord(string w){
        return findWord(root, w);
     }
     
     TrieNode* findWord(TrieNode* root,string word){
        if(word.size()==0){
         return root;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return NULL;
        }
        return findWord(child, word.substr(1));
     }

     void insertWord(string word){
        insertWord(root,word);
     }

     void insertWord(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child,word.substr(1));
     }

    bool searchWord(string word){
        return searchWord(root,word);
     }

     bool searchWord(TrieNode* root, string word){
        if(word.size()==0){
         return root->isTerminal;
         //return true; (for pattern matching)
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchWord(child, word.substr(1));
     }

    void removeWord(string word){
        removeWord(root,word); 
    }

     void removeWord(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return;
        }
        removeWord(child, word.substr(1));
        //removing child if useless
        if(child->isTerminal==false){
        //now checking if child has children
          for(int i=0; i<26; i++){
            if(root->children[i]!=NULL){
                return;
          }
          }
          delete child; //deallocating child 
          root->children[index]=NULL;
        }
        

     }

};