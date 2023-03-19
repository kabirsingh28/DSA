#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
#include "BST.h"
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Pair
{
public:
    node *head;
    node *tail;
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

void printRange(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;
    if (root->data > k1 && root->data < k2)
    {
        printRange(root->left, k1, k2);
        cout << root->data << " ";
        printRange(root->right, k1, k2);
    }
    else if (root->data >= k2)
    {
        if (root->data == k2)
            cout << root->data << " ";
        printRange(root->left, k1, k2);
    }
    else if (root->data <= k1)
    {
        if (root->data == k1)
            cout << root->data << " ";
        printRange(root->right, k1, k2);
    }
}

int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->right), maximum(root->left)));
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data <= rightMin) && (root->data > leftMax) && isBST(root->left) && isBST(root->right);
    return output;
}

void print_LL(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Pair BST_LL(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair p;
        p.head = NULL;
        p.tail = NULL;
        return p;
    }
    Pair leftLL = BST_LL(root->left);
    Pair rightLL = BST_LL(root->right);
    node *newNode = new node(root->data);
    Pair ans;
    if (leftLL.head == NULL && rightLL.head == NULL)
    {
        ans.head = newNode;
        ans.tail = newNode;
    }
    else if (leftLL.head == NULL && rightLL.head != NULL)
    {
        newNode->next = rightLL.head;
        ans.head = newNode;
        ans.tail = rightLL.tail;
    }
    else if (leftLL.head != NULL && rightLL.head == NULL)
    {
        leftLL.tail->next = newNode;
        ans.head = leftLL.head;
        ans.tail = newNode;
    }
    else
    {
        leftLL.tail->next = newNode;
        newNode->next = rightLL.head;
        ans.head = leftLL.head;
        ans.tail = rightLL.tail;
    }
    return ans;
}

vector<int> *getRootNodepath(BinaryTreeNode<int> *root, int element)
{
    if (root == NULL)
        return NULL;
    if (root->data == element)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftPath = getRootNodepath(root->left, element);
    if (leftPath != NULL)
    {
        leftPath->push_back(root->data);
        return leftPath;
    }
    vector<int> *rightPath = getRootNodepath(root->right, element);
    if (rightPath != NULL)
    {
        rightPath->push_back(root->data);
        return rightPath;
    }
    else
    {
        return NULL;
    }
}

vector<int> *get_path(BinaryTreeNode<int> *root, int element)
{
    if (root == NULL)
        return NULL;
    if (root->data == element)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    else if (root->data < element)
    {
        vector<int> *rightPath = get_path(root->right, element);
        if (rightPath != NULL)
        {
            rightPath->push_back(root->data);
            return rightPath;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        vector<int> *leftPath = get_path(root->left, element);
        if (leftPath != NULL)
        {
            leftPath->push_back(root->data);
            return leftPath;
        }
        else
        {
            return NULL;
        }
    }
}

int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.print();
    cout<<endl<<endl;
    b.deleteData(10);
    b.deleteData(100);
    b.print();
    // cout<<b->hasData(4);
    // BinaryTreeNode<int> * root = takeinput_levelwise();
    //  int element;
    //  cin>>element;
    //  vector<int> * output = getRootNodepath(root,element);
    //  for(int i=0; i<output->size(); i++){
    //      cout<<output->at(i)<<" ";
    //  }
    //  vector<int> * path = get_path(root,element);
    //  for(int i=0; i<path->size(); i++){
    //      cout<<path->at(i)<<" ";
    //  }
    //  print_LL(BST_LL(root).head);
    //  if(isBST(root)) cout<<"true";
    //  else cout<<"false";
    //  int k1,k2;
    //  cin>>k1>>k2;
    //  printRange(root,k1,k2);
    return 0;
}