#include<bits/stdc++.h>
using namespace std;
#include "treenode.h"
#include <queue>

treenode<int>* takeinput_levelWise(){
    //taking the input of data of root node cause this is the main node which will be returned
    int rootData;
    cout<<"Enter the data of root node: ";
    cin>>rootData;
    //creating the root node dynamically and initiallizing it with rootData
    treenode<int> * root = new treenode<int>(rootData);
    //now pushing the address of root node into pendingNode queue
    queue<treenode<int>*> pendingNode;
    pendingNode.push(root);
    //now untill this queue isn't empty we will run a while loop to construct the tree
    while(!pendingNode.empty()){
        //we will be taking the front element's address from the queue store it in a pointer and pop it
        //then we will ask how many children it has
        treenode<int> * front = pendingNode.front(); //front->data for 1st iteration be rootData
        pendingNode.pop();
        int n;
        cout<<"Enter the number of children of "<<front->data<<": ";
        cin>>n;
        //will be running a for loop to input the data of children of root and also making connections
        for(int i=0; i<n; i++){
            int childData;
            cout<<"Enter the data of "<<i<<" th child of "<<front->data<<": ";
            cin>>childData;
            //creating child node
            treenode<int> * child = new treenode<int>(childData);
            //now pushing each child into the pendingNode queue
            pendingNode.push(child);
            //and then connecting child node with parent node
            front->children.push_back(child);
        }
    }
    //after that will be returning the root nodes address
    return root;

}

void print(treenode<int> * root){
    queue<treenode<int>*> pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        //printing the node
        treenode<int> * front = pendingNode.front();
        cout<<front->data<<": ";
        //poping the front element
        pendingNode.pop();
        //printing it's children
        for(int i=0; i<front->children.size(); i++){
            cout<<front->children[i]->data<<",";
            //pushing the children's address into the queue
            pendingNode.push(front->children[i]);
        }
        cout<<endl;
    }
}

int count_nodes(treenode<int> * root){
    int ans=1;
    for(int i=0; i<root->children.size(); i++){
          ans+=count_nodes(root->children[i]);
    }
    return ans;
}

int sum_nodes(treenode<int> * root){
    int ans = root->data;
    for(int i=0; i<root->children.size(); i++){
        ans+=sum_nodes(root->children[i]);
    }
    return ans;
}

int largest_node(treenode<int> * root){
    if(root==NULL) return -1;
    int largest = root->data;
    for(int i=0; i<root->children.size(); i++){
        int child_data = largest_node(root->children[i]);
        if(largest<child_data){
          largest = child_data;
        }
    }
    return largest;
}

int main()
{   treenode<int> * root = takeinput_levelWise();
    // cout<<endl<<"printing tree level wise: "<<endl;
    // print(root);
    //cout<<sum_nodes(root);
    cout<<largest_node(root);
    return 0;
}