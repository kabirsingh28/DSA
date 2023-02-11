#include<bits/stdc++.h>
using namespace std;
#include "treenode.h"

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

int count_nodes(int x, treenode<int> * root){
    int ans = 0;
    if(root==NULL) return 0;
    if(root->data>x) {
        ans++;
    }
    for(int i=0; i<root->children.size(); i++){
       ans+= count_nodes(x,root->children[i]);
    }
    return ans;
}

bool contains_x(int x, treenode<int> * root){
    if(root==NULL) return false;
    if(root->data==x) return true;
    for(int i=0; i<root->children.size(); i++){
        if(contains_x(x,root->children[i])) return true;
    }
    return false;
}

int main()
{   treenode<int> * root = takeinput_levelWise();
    int x;
    cin>>x;
    if(contains_x(x,root)) cout<<"true ";
    else cout<<"false ";
    cout<<count_nodes(x,root);
    return 0;
}