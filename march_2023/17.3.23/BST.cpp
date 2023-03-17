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

void level_order(BinaryTreeNode<int> * root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> pendingQueue;
    pendingQueue.push(root);
    pendingQueue.push(NULL);
    while(!pendingQueue.empty()){
        BinaryTreeNode<int> * front = pendingQueue.front();
        pendingQueue.pop();
        if(pendingQueue.empty()) break;
        if(front==NULL){
            cout<<endl;
            pendingQueue.push(NULL);
        }
        else{
        cout<<front->data<<" ";
        if(front->left!=NULL) pendingQueue.push(front->left);
        if(front->right!=NULL) pendingQueue.push(front->right);
        }
    }
}

BinaryTreeNode<int>* construct_BST(int * arr,int start, int end){
     if(start>end) return NULL;
     int mid = (start+end)/2;
     BinaryTreeNode<int> * root = new BinaryTreeNode<int>(arr[mid]);
     root->left = construct_BST(arr,start,mid-1);
     root->right = construct_BST(arr,mid+1,end);
     return root;
   }

int main()
{   //BinaryTreeNode<int> * root = takeinput_levelwise();
    int n;
    cin>>n;
    int * arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    level_order(construct_BST(arr,0,n-1));
    delete [] arr;
    // int k1,k2;
    // cin>>k1>>k2;
    // printRange(root,k1,k2);
    return 0;
}