#include <bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

class data{
    public:
    int min;
    int max;
    bool isBST; 
    int height;
};

BinaryTreeNode<int> *takeinput_levelwise()
{
    int rootData;
    cout << "Enter root data:" << endl;
    cin >> rootData; 
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingQueue;
    pendingQueue.push(root);
    while (!pendingQueue.empty())
    {
        BinaryTreeNode<int> *front = pendingQueue.front();
        pendingQueue.pop();
        cout << "Enter left child of " << front->data << ": " << endl;
        int left_child;
        cin >> left_child;
        if (left_child != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(left_child);
            front->left = leftChild;
            pendingQueue.push(leftChild);
        }
        cout << "Enter right child of " << front->data << ": " << endl;
        int right_child;
        cin >> right_child;
        if (right_child != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(right_child);
            front->right = rightChild;
            pendingQueue.push(rightChild);
        }
    }
    return root;
}

void level_order(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingQueue;
    pendingQueue.push(root);
    pendingQueue.push(NULL);
    while (!pendingQueue.empty())
    {
        BinaryTreeNode<int> *front = pendingQueue.front();
        pendingQueue.pop();
        if (pendingQueue.empty())
            break;
        if (front == NULL)
        {
            cout << endl;
            pendingQueue.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
                pendingQueue.push(front->left);
            if (front->right != NULL)
                pendingQueue.push(front->right);
        }
    }
}

BinaryTreeNode<int> *create_insert_duplicate(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *temp = root->left;
    root->left = newNode;
    newNode->left = create_insert_duplicate(temp);
    root->right = create_insert_duplicate(root->right);
    return root;
}

void convertToVector(BinaryTreeNode<int> * root, vector<int> &v){
    if(root==NULL) return;
    v.push_back(root->data);
    convertToVector(root->left,v);
    convertToVector(root->right,v);
}

void pair_sum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> v;
    convertToVector(root,v);
    sort(v.begin(), v.end());
    int i = 0;
    int j = v.size() - 1;
    while (i<j)
    {
        int currentSum = v[i] + v[j];
        if (currentSum == sum)
        {  cout<<v[i]<<" "<<v[j]<<endl;
           i++;
           j--;
        }
        else if(currentSum<sum){
          i++;
        }
        else{
          j--;
        }
    }
}

BinaryTreeNode<int>* LCA(BinaryTreeNode<int> * root, int n1, int n2){
    if(root==NULL) return NULL;
    if(n1==root->data || n2==root->data) return root;
    BinaryTreeNode<int> * a = LCA(root->left,n1,n2);
    BinaryTreeNode<int> * b = LCA(root->right,n1,n2);
    if(a!=NULL && b==NULL) return a;
    else if(a==NULL && b==NULL) return NULL;
    else if(a==NULL && b!=NULL) return b;
    else return root;
}

BinaryTreeNode<int>* LCA_BST(BinaryTreeNode<int> * root, int n1, int n2){
    if(root==NULL) return NULL;
    if(n1==root->data || n2==root->data) return root;
    else if(n1<root->data && n2<root->data){
        return LCA_BST(root->left,n1,n2);
    }
    else if(n1>root->data && n2>root->data){
        return LCA_BST(root->right,n1,n2);
    }
    else if(n1<root->data && n2>root->data){
        return root;
    }
}

data largest_BST(BinaryTreeNode<int> * root){
   if(root==NULL){
    data d;
    d.min = INT_MAX;
    d.max = INT_MIN;
    d.isBST = true;
    d.height = 0;
    return d;
   }

   data leftans = largest_BST(root->left);
   data rightans = largest_BST(root->right);
   data finalans;
   finalans.min = min(root->data,min(leftans.min, rightans.min));
   finalans.max = max(root->data,max(leftans.max, rightans.max));
   finalans.isBST = leftans.isBST && rightans.isBST && (root->data<=rightans.min) && (root->data>leftans.max);
   if(finalans.isBST) finalans.height = 1 + max(leftans.height, rightans.height);
   else finalans.height = max(leftans.height, rightans.height);
   return finalans;
}

void rootToleaf_path(BinaryTreeNode<int> * root, int K, int currentSum, vector<int>& v){
    if(root==NULL) return;
    
    currentSum += root->data;
    v.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        if(currentSum == K){
            for(int i=0; i<v.size(); i++){
                cout<<v.at(i)<<" ";
            }
            cout<<endl;
        }
    } 
    else{
        rootToleaf_path(root->left, K, currentSum, v);
        rootToleaf_path(root->right, K, currentSum, v);
    }

    v.pop_back();
      
}

void printNodeAtDepth(BinaryTreeNode<int>* root,int K){
    if(root==NULL || K<0) return;
    if(K==0){
     cout<<root->data<<" ";
     return;
    }
    printNodeAtDepth(root->left,K-1);
    printNodeAtDepth(root->right,K-1);
}

//function return distance of currentRoot to target
int printNodesAtK(BinaryTreeNode<int>* root, int target, int K){
    if(root->data==target){
        printNodeAtDepth(root,K);
        return 0;
        }

    if(root==NULL) return -1;
    int leftDistance = printNodesAtK(root->left,target,K);
    //if leftdistance = -1 means root is not reachable, but
    //if it is reachable then, 
    //if leftdistance + 1 (1 is for root node) = K then
    //we will be printing root cause then root will be K 
    //distance apart from target
    if(leftDistance!=-1){
    if(leftDistance+1==K) cout<<root->data<<" ";
    else{
      printNodeAtDepth(root->right,K-leftDistance-2);
    }
    return leftDistance + 1;
    }

    int rightDistance = printNodesAtK(root->right,target,K);
    if(rightDistance!=-1){
    if(rightDistance+1==K) cout<<root->data<<" ";
    else{
       printNodeAtDepth(root->left,K-rightDistance-2);
    }
    return 1 + rightDistance;
    }
    return -1;
}

// bool isPresent(BinaryTreeNode<int>* root, int data){
//     if(root==NULL) return false;
//     if(root->data==data||isPresent(root->left,data)||isPresent(root->right,data)) return true;
//     else return false;
// }

// void printSum(BinaryTreeNode<int>* root, int sum){
//      if(root==NULL) return;
//      if(isPresent(root,sum-root->data)||isPresent(root,sum-root->data)){
//         if(root->data<sum-root->data){
//             cout<<root->data<<" "<<sum-root->data<<endl;
//         }
//         else{
//             cout<<sum-root->data<<" "<<root->data<<endl;
//         }
//      }
//      printSum(root->left,sum);
//      printSum(root->right,sum);
// }

void inorder(BinaryTreeNode<int>* root,vector<int> &arr){
    if(!root) return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

void printSum(BinaryTreeNode<int>* root, int s){
    vector<int> arr;
    inorder(root,arr);
    int i=0;
    int j= arr.size()-1;
    bool b = false;
    while(i<j){
        if(arr[i]+arr[j]==s){
             b=true;
            j--;
            i++;
            cout<<arr[i]<<","<<arr[j]<<endl;
           
        }
        else if(arr[i]+arr[j]>s) j--;
        else i++;
    }
    if(b==false) cout<<"-1";
    }


int main()
{
    BinaryTreeNode<int> *root = takeinput_levelwise();
    int sum;
    cin>>sum;
    printSum(root,sum);
    // int sum;
    // cin>>sum;
    // printSum(root,sum);
    // int target, K;
    // cin>>target>>K;
    // int t = printNodesAtK(root,target,K);
    // int K;
    // cin>>K;
    // vector<int> v;
    // rootToleaf_path(root,K,0,v);
    // level_order(root);
    // replace_sum(root);
    // level_order(root);
    //cout<<largest_BST(root).height;
    // int n1,n2;
    // cin>>n1>>n2;
    // cout<<LCA_BST(root,n1,n2)->data;
    //cout<<LCA(root,n1,n2)->data;
    // int sum;
    // cin >> sum;
    // pair_sum(root, sum);
    // level_order(root);
    // cout<<endl<<endl;
    // level_order(create_insert_duplicate(root));
    return 0;
}