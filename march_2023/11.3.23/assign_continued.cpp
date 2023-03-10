#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

template <typename T, typename S>
class Pair{
    public:
    T height;
    S isBalanced;
};

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

int sum(BinaryTreeNode<int> * root){
    if(root==NULL) return 0;
    return root->data + sum(root->left) + sum(root->right);
}

int height(BinaryTreeNode<int> * root){
    if(root==NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}

bool is_balanced(BinaryTreeNode<int> * root){
    if(root==NULL) return true;
    if(abs(height(root->left) - height(root->right))>1){
        return false;
    }
    else{
        return is_balanced(root->left) && is_balanced(root->right);
    }
}

Pair<int,bool> bal_height(BinaryTreeNode<int> * root){
    if(root==NULL){
        Pair<int,bool> p;
        p.height = 0;
        p.isBalanced = true;
        return p;
    }

    Pair<int,bool> a = bal_height(root->left);
    Pair<int,bool> b = bal_height(root->right);

    Pair<int,bool> ans;
    ans.height = 1 + max(a.height,b.height);
    ans.isBalanced = (a.isBalanced && b.isBalanced) && (abs(b.height - a.height)<=1?true:false);
    return ans;

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

int main()
{  BinaryTreeNode<int> * root = takeinput_levelwise();
   level_order(root);
//    if(bal_height(root).isBalanced) cout<<"true";
//    else cout<<"false";
//    if(is_balanced(root)) cout<<"true";
//    else cout<<"false";
   //cout<<sum(root);
    return 0;
}