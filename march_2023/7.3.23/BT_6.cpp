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

bool is_node_present(BinaryTreeNode<int> * root, int x){
    if(root==NULL) return false;
    if(root->data==x || is_node_present(root->left,x) || is_node_present(root->right,x)) return true;
    else return false;
}

int height(BinaryTreeNode<int> * root){
    if(root==NULL) return 0;
    int h = max(height(root->left),height(root->right)) + 1;
    return h;
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

void mirror_bt(BinaryTreeNode<int> * root){
    if(root==NULL) return;
    BinaryTreeNode<int> * temp = root->left;
    root->left = root->right;
    root->right = temp;   
    mirror_bt(root->left);
    mirror_bt(root->right);
}

void in_order(BinaryTreeNode<int> * root){
    if(root==NULL) return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);

}

int main()
{  BinaryTreeNode<int> * root = takeinput_levelwise();
//    print_levelwise(root);
//    mirror_bt(root);
//    print_levelwise(root);
      in_order(root);
//    int x;
//    cin>>x;
//    if(is_node_present(root,x)) cout<<"true";
//    else cout<<"false";
//    cout<<height(root);
   return 0;
}