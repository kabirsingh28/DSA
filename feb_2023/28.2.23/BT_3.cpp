#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"
#include <queue>

BinaryTreeNode<int>* takeinput_levelWise(){
    int rootData;
    cout<<"enter root data: ";
    cin>>rootData;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    //we will be storing address of nodes into the queue
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter left child of "<<front->data<<": ";
        int childDataLeft;
        cin>>childDataLeft;
        if(childDataLeft!=-1){
          BinaryTreeNode<int>* childleft = new BinaryTreeNode<int>(childDataLeft);
          front->left = childleft;
          pendingNodes.push(childleft);
        }
        cout<<"enter right child of "<<front->data<<": ";
        int childDataRight;
        cin>>childDataRight;
        if(childDataRight!=-1){
          BinaryTreeNode<int>* childRight = new BinaryTreeNode<int>(childDataRight);
          front->right = childRight;
          pendingNodes.push(childRight);
        }
    }
    return root;
    
}

void print_bt(BinaryTreeNode<int> * root){
    if(root == NULL) return;
    cout<<root->data<<":";
    if(root->left!=NULL){
    cout<<"L"<<root->left->data<<",";
    }
     if(root->right!=NULL){
    cout<<"R"<<root->right->data;
    }
    cout<<endl;
    print_bt(root->left);
    print_bt(root->right);
}

int main()
{   BinaryTreeNode<int> * root = takeinput_levelWise();
    print_bt(root);
    return 0;
}