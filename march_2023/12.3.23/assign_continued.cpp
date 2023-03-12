#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

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

BinaryTreeNode<int>* remove_leafs(BinaryTreeNode<int> * root){
    if(root->left==NULL && root->right==NULL) return NULL;
    if(root->left!=NULL) root->left = remove_leafs(root->left);
    if(root->right!=NULL) root->right = remove_leafs(root->right);
    return root;
}

vector<node*> levelWise_LL(BinaryTreeNode<int> * root){
    queue<BinaryTreeNode<int>*> pendingQueue;
    pendingQueue.push(root);
    pendingQueue.push(NULL);
    node * head = NULL;
    node * tail = NULL;
    vector<node*> v;
    while(!pendingQueue.empty()){
        BinaryTreeNode<int> * front = pendingQueue.front();
        pendingQueue.pop();
        if(front==NULL){
            v.push_back(head);
            if(pendingQueue.empty()) break;
            pendingQueue.push(NULL);
            head = NULL;
            tail = NULL;
        }
        else{
            node * newNode = new node(front->data);
            if(head==NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
            if(front->left!=NULL) pendingQueue.push(front->left);
            if(front->right!=NULL) pendingQueue.push(front->right);

        }
    }
    return v;
}

void nodes_without_siblings(BinaryTreeNode<int> * root){
    if(root==NULL) return;
    if(root->left!=NULL && root->right==NULL) cout<<root->left->data<<" ";
    if(root->right!=NULL && root->left==NULL) cout<<root->right->data<<" ";
    nodes_without_siblings(root->left);
    nodes_without_siblings(root->right);
}

void zig_zag(BinaryTreeNode<int> * root){
    stack<BinaryTreeNode<int>*> pendingStack_1;
    stack<BinaryTreeNode<int>*> pendingStack_2;
    pendingStack_1.push(root);
    while(!pendingStack_1.empty() || !pendingStack_2.empty()){
        while(!pendingStack_1.empty()){
        BinaryTreeNode<int> * top = pendingStack_1.top();
        pendingStack_1.pop();
            cout<<top->data<<" ";
            if(top->left!=NULL) pendingStack_2.push(top->left);
            if(top->right!=NULL) pendingStack_2.push(top->right);
    }
    if(!pendingStack_2.empty()) cout<<endl;
        while(!pendingStack_2.empty()){
        BinaryTreeNode<int> * top = pendingStack_2.top();
        pendingStack_2.pop();
            cout<<top->data<<" ";
            if(top->right!=NULL) pendingStack_1.push(top->right);
            if(top->left!=NULL) pendingStack_1.push(top->left);
    }
    if(!pendingStack_1.empty()) cout<<endl;
    }
}

int main()
{  BinaryTreeNode<int> * root = takeinput_levelwise();
   zig_zag(root);
//    nodes_without_siblings(root);
//    vector<node*> v = levelWise_LL(root);
//    for(int i=0; i<v.size(); i++){
//     cout<<v[i]->data<<" ";
//    }
//    level_order(root);
//    cout<<endl<<endl;
//    level_order(remove_leafs(root));
//    if(bal_height(root).isBalanced) cout<<"true";
//    else cout<<"false";
//    if(is_balanced(root)) cout<<"true";
//    else cout<<"false";
   //cout<<sum(root);
    return 0;
}