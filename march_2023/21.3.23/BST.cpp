#include <bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

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

int main()
{
    BinaryTreeNode<int> *root = takeinput_levelwise();
    int n1,n2;
    cin>>n1>>n2;
    cout<<LCA(root,n1,n2)->data;
    // int sum;
    // cin >> sum;
    // pair_sum(root, sum);
    // level_order(root);
    // cout<<endl<<endl;
    // level_order(create_insert_duplicate(root));
    return 0;
}