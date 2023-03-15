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

void printRange(BinaryTreeNode<int> * root, int k1, int k2){
    if(root==NULL) return;
    if(root->data>k1 && root->data<k2){
        printRange(root->left,k1,k2);
        cout<<root->data<<" ";
        printRange(root->right,k1,k2);
    }
    else if(root->data>=k2){
        if(root->data==k2) cout<<root->data<<" ";
        printRange(root->left,k1,k2);
    }
    else if(root->data<=k1){
        if(root->data==k1) cout<<root->data<<" ";
        printRange(root->right,k1,k2);                                                 
    }
}

int maximum(BinaryTreeNode<int> * root){
    if(root==NULL) return INT_MIN;
    return max(root->data,max(maximum(root->right),maximum(root->left)));
}

int minimum(BinaryTreeNode<int> * root){
    if(root==NULL) return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}


bool isBST(BinaryTreeNode<int> * root){
    if(root==NULL) return true;
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data<=rightMin) && (root->data>leftMax) && isBST(root->left) && isBST(root->right);
    return output;
}

int main()
{   BinaryTreeNode<int> * root = takeinput_levelwise();
    if(isBST(root)) cout<<"true";
    else cout<<"false";
    // int k1,k2;
    // cin>>k1>>k2;
    // printRange(root,k1,k2);
    return 0;
}