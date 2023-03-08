#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

BinaryTreeNode<int>* takeinput_levelwise(){
   int rootData;
   cout<<"Enter root data:"<<endl;
   cin>>rootData;
   if(rootData==-1) return NULL;
   BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
   queue<BinaryTreeNode<int>*> pendingQueue;
   pendingQueue.push(root);
   while(!pendingQueue.empty()){
    BinaryTreeNode<int> * front = pendingQueue.front();
    pendingQueue.pop();
    cout<<"Enter left child of "<<front->data<<": "<<endl;
    int left_child;
    cin>>left_child;
    if(left_child!=-1){
        BinaryTreeNode<int> * leftChild = new BinaryTreeNode<int>(left_child);
        front->left = leftChild;
        pendingQueue.push(leftChild);
    }
    cout<<"Enter right child of "<<front->data<<": "<<endl;
    int right_child;
    cin>>right_child;
    if(right_child!=-1){
        BinaryTreeNode<int> * rightChild = new BinaryTreeNode<int>(right_child);
        front->right = rightChild;
        pendingQueue.push(rightChild);
    }
    
   }
   return root;
}

void print_levelwise(BinaryTreeNode<int> * root){
    queue<BinaryTreeNode<int>*> pendingQueue;
    pendingQueue.push(root);
    while(!pendingQueue.empty()){
        BinaryTreeNode<int> * front = pendingQueue.front();
        pendingQueue.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<",";
            pendingQueue.push(front->left);
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data;
            pendingQueue.push(front->right);
        }
        cout<<endl;
    }
}

void pre_order(BinaryTreeNode<int> * root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(BinaryTreeNode<int> * root){
    if(root==NULL) return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}


int main()
{   BinaryTreeNode<int> * root = takeinput_levelwise();
    //pre_order(root);
    //post_order(root);
    return 0;
}