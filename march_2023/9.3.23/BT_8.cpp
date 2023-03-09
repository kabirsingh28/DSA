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

BinaryTreeNode<int>* construct(int * pre, int * in, int preS, int preE, int inS, int inE ){
    if(inE<inS) return NULL;
   BinaryTreeNode<int> * root = new BinaryTreeNode<int>(pre[preS]);
   int LinS = inS;
   int i=0;
   while(in[i]!=root->data){
    i++;
   }
   int LinE = i-1;
   int LpreS = preS+1;
   int LpreE = LpreS + LinE - LinS;
   BinaryTreeNode<int> * leftChild = construct(pre,in,LpreS,LpreE,LinS,LinE);
   root->left = leftChild;
   int RinS = i+1;
   int RinE = inE;
   int RpreS = LpreE+1;
   int RpreE = preE;
   BinaryTreeNode<int> * rightChild = construct(pre,in,RpreS,RpreE,RinS,RinE);
   root->right = rightChild;
   return root;
}

BinaryTreeNode<int>* construct_2(int * pos, int * in, int posS, int posE, int inS, int inE ){
    if(inE<inS) return NULL;
   BinaryTreeNode<int> * root = new BinaryTreeNode<int>(pos[posE]);
   int LinS = inS;
   int i=0;
   while(in[i]!=root->data){
    i++;
   }
   int LinE = i-1;
   int LposS = posS;
   int LposE = LposS + LinE - LinS;
   BinaryTreeNode<int> * leftChild = construct_2(pos,in,LposS,LposE,LinS,LinE);
   root->left = leftChild;
   int RinS = i+1;
   int RinE = inE;
   int RposS = LposE+1;
   int RposE = posE-1;
   BinaryTreeNode<int> * rightChild = construct_2(pos,in,RposS,RposE,RinS,RinE);
   root->right = rightChild;
   return root;
}

int height(BinaryTreeNode<int> * root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right)) + 1;
}

int diameter(BinaryTreeNode<int> * root){
    if(root==NULL) return 0;
    int a = height(root->left) + height(root->right);
    int b = diameter(root->left);
    int c = diameter(root->right);
    return max(a,max(b,c));
}

pair<int,int> diameter_height(BinaryTreeNode<int> * root){
    if(root==NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftAns = diameter_height(root->left);
    pair<int,int> rightAns = diameter_height(root->right);

    int ld = leftAns.second;
    int rd = rightAns.second;
    int lh = leftAns.first;
    int rh = rightAns.first;

    int overall_height = 1 + max(lh,rh);
    int overall_diameter = max(lh+rh, max(rd,ld));
    pair<int,int> p;
        p.first = overall_height;
        p.second = overall_diameter;
        return p;
}

pair<int,int> max_1n2(BinaryTreeNode<int> * root){

    if(root==NULL){
        pair<int,int> p;
        p.first = -1;
        p.second = -1;
        return p;
    }

    pair<int,int> leftans = max_1n2(root->left);
    pair<int,int> rightans = max_1n2(root->right);

    pair<int,int> ans;
    if(leftans.first>rightans.first){
        ans.first = leftans.first;
        if(rightans.first>leftans.second){
        ans.second = rightans.first;
        }
        else{
            ans.second = leftans.second;
        }
    }
    else{
        ans.first = rightans.first;
        if(leftans.first>rightans.second){
        ans.second = leftans.first;
        }
        else{
            ans.second = rightans.second;
        }
    }
    if(root->data>ans.first){
       ans.second = ans.first;
       ans.first = root->data;
    }
    else if(root->data>ans.second){
        ans.second = root->data;
    }
    return ans;
}

// pair<int,int> extremes(BinaryTreeNode<int> * root){
//       if(root==NULL){
//         pair<int,int> p;
//         p.first = -1;
//         p.second = -1;
//         return p;
//     }

//     pair<int,int> leftans = extremes(root->left);
//     pair<int,int> rightans = extremes(root->right);

//     pair<int,int> ans;
//     ans.first = max(root->data,max(leftans.first,rightans.first));
//     int temp;
//     if(leftans.second==-1 || rightans.second==-1){
//         if(max(leftans.second,rightans.second)==-1){
//         ans.second = root->data;
//         }
//         else ans.second = min(root->data,max(leftans.second,rightans.second));
//     }
//     else ans.second = min(root->data,min(leftans.second,rightans.second));
//     return ans;
// }

pair<int,int> extremes(BinaryTreeNode<int> * root){
      if(root==NULL){
        pair<int,int> p;
        p.first = INT_MIN;
        p.second = INT_MAX;
        return p;
    }

    pair<int,int> leftans = extremes(root->left);
    pair<int,int> rightans = extremes(root->right);

    pair<int,int> ans;
    ans.first = max(root->data,max(leftans.first,rightans.first));
    ans.second = min(root->data,min(leftans.second,rightans.second));
    return ans;
}

int main()
{   BinaryTreeNode<int> * root = takeinput_levelwise();
    cout<<extremes(root).first<<" "<<extremes(root).second;
    //cout<<max_1n2(root).first<<" "<<max_1n2(root).second;
    //cout<<diameter_height(root).second;
    // int n;
    // cin>>n;
    // int * pos = new int[n];
    // for(int i=0; i<n; i++){
    //     cin>>pos[i];
    // }
    // int * in = new int[n];
    // for(int i=0; i<n; i++){
    //     cin>>in[i];
    // }
    // int posS = 0;
    // int posE = n-1;
    // int inS = 0;
    // int inE = n-1;
    // BinaryTreeNode<int> * root = construct_2(pos, in, posS, posE, inS, inE);
    // // construct(pre, in, preS, preE, inS, inE);
    // //pre_order(root);
    // //post_order(root);
    // print_levelwise(root);
    return 0;
}