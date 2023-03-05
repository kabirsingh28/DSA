#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"
#include <queue>

void print_bt(BinaryTreeNode<int> * root){
    if(root == NULL) return;
    cout<<root->data<<": ";
    if(root->left!=NULL) cout<<"L"<<root->left->data<<",";
    if(root->right!=NULL) cout<<"R"<<root->right->data;
    cout<<endl;
    print_bt(root->left);
    print_bt(root->right);
}

BinaryTreeNode<int>* takeinput(){
    int rootData;
    cout<<"enter data: ";
    cin>>rootData;
    if(rootData==-1) return NULL;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> * child_left = takeinput();
    BinaryTreeNode<int> * child_right = takeinput();
    root->left = child_left;
    root->right = child_right;
    return root;

}

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


int main()
{  BinaryTreeNode<int> * root = takeinput_levelwise();
   print_bt_levelwise(root);
   return 0;
}