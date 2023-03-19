#include <iostream>
using namespace std;
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return false;
        if (root->data == data)
            return true;
        else if (root->data < data)
            return hasData(data, root->right);
        else
            return hasData(data, root->left);
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> * root)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            return node;
        }
        if (root->data <= data)
        {
            root->right = insert(data, root->right);
        }
        else
        {
            root->left = insert(data, root->left);
        }
        return root;
    }

    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int> * root)
    {
        if (root == NULL)
            return NULL;
        if (root->data == data)
        {
            // 4 cases either it can be leaf node or node
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else if (root->left == NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else
            { // root->left->data!=data && root->right->data!=data
                BinaryTreeNode<int> *minNode = root->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                root->data = minNode->data;
                root->right = deleteData(minNode->data, root->right);
                return root;
            }
        }
        else if (root->data < data){
            root->right = deleteData(data, root->right);
            return root;
        }
        else{
            root->left = deleteData(data, root->left);
            return root;
        }
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

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void insert(int data)
    {
        root = insert(data, root);
    }

    void deleteData(int data)
    {
        root = deleteData(data, root);
    }

    void print()
    {
        level_order(root);
    }
};