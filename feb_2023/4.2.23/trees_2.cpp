#include<bits/stdc++.h>
using namespace std;
#include <queue>
#include "treenode.h"

treenode<int>* TakeInputLevleWise(){
    int rootData;
    cout<<"enter root data: ";
    cin>>rootData;
    treenode<int> * root = new treenode<int>(rootData);
    queue<treenode<int>*> pending_nodes;
    pending_nodes.push(root);
    while(!pending_nodes.empty()){
        treenode<int> * front = pending_nodes.front();
        pending_nodes.pop();
        int n;
        cout<<"enter number of children of "<<front->data<<": ";
        cin>>n;
        for(int i=0; i<n; i++){
            int childData;
            cout<<"enter data of "<<i<<" th child of "<<front->data<<": ";
            cin>>childData;
            treenode<int> * child = new treenode<int>(childData);
            front->children.push_back(child);
            pending_nodes.push(child);
        }
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

int main()
{   treenode<int> * root = TakeInputLevleWise();
    print(root);
    return 0;
}