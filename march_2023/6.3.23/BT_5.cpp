#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

BinaryTreeNode<int>* takeinput_levelwise(){
   int rootData;
   cout<<"Enter root data: ";
   cin>>rootData;
   if(rootData==-1) return NULL;
   BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
   queue<BinaryTreeNode<int>*> pendingQueue;
   pendingQueue.push(root);
   while(!pendingQueue.empty()){
    BinaryTreeNode<int> * front = pendingQueue.front();
    pendingQueue.pop();
    cout<<"Enter left child of "<<front->data<<": ";
    int left_child;
    cin>>left_child;
    if(left_child!=-1){
        BinaryTreeNode<int> * leftChild = new BinaryTreeNode<int>(left_child);
        front->left = leftChild;
        pendingQueue.push(leftChild);
    }
    cout<<"Enter right child of "<<front->data<<": ";
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

int count_nodes(BinaryTreeNode<int> * root){
    if(root==NULL) return 0;
    int ans=1;
    ans+=count_nodes(root->left)+count_nodes(root->right);
    return ans;
}

int main()
{   BinaryTreeNode<int> * root = takeinput_levelwise();
    //print_levelwise(root);
    cout<<count_nodes(root);
    return 0;
}