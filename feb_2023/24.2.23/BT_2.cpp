#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

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

BinaryTreeNode<int>* takeinput(){
    int rootData;
    cout<<"enter data: ";
    cin>>rootData;
    // if the user input -1 as root data that means that node doesnt exsist
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeinput();
    BinaryTreeNode<int>* rightChild = takeinput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main()
{   
    // BinaryTreeNode<int> * root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> * node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> * node2 = new BinaryTreeNode<int>(3);

    // root->left = node1;
    // root->right = node2;

    BinaryTreeNode<int> * root = takeinput();
    
    print_bt(root);
    
    delete root;
    return 0;
}