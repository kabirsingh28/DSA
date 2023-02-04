#include<bits/stdc++.h>
using namespace std;
#include "treenode.h"

treenode<int>* takeinput(){
    int rootData;
    cout<<"enter data: ";
    cin>>rootData;
    treenode<int> * root = new treenode<int>(rootData);
    int n;
    cout<<"enter number of children of "<<rootData<<": ";
    cin>>n;
    for(int i=0; i<n; i++){
       treenode<int> * child = takeinput();
       root->children.push_back(child); //saving addresses of children in the parent node
    }
    return root;
}

void print(treenode<int> * root){
    if(root==NULL){ //not a base case instead it's a edge case
        return;
    }
    cout<<root->data<<":";
    for(int i=0; i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        print(root->children[i]);
    }
}

int main(){
//   //creating nodes
//     treenode<int> * root = new treenode<int>(1);
//     treenode<int> * node_1 = new treenode<int>(2);
//     treenode<int> * node_2 = new treenode<int>(3);
    
//     //connecting
//     root->children.push_back(node_1);
//     root->children.push_back(node_2);
    
    treenode<int> * root = takeinput();
    print(root);

    return 0;
}