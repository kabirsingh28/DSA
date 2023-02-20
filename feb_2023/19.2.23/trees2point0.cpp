#include<bits/stdc++.h>
using namespace std;
#include "treenode.h"

template <typename T>
class Pair{
    public:
    T data;
    T sum;
};

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

Pair<int> max_childSum(treenode<int> * root){
    Pair<int> p;
    p.data = root->data;
    p.sum = root->data;

    for(int i=0; i<root->children.size(); i++){
        p.sum+=root->children[i]->data;
    }

    for(int i; i<root->children.size(); i++){
        Pair<int> child = max_childSum(root->children[i]);
        if(p.sum<child.sum){
            p.sum = child.sum;
            p.data = child.data;
        }
    }

    return p;


}

bool struct_equall(treenode<int> * root1, treenode<int> * root2){
    int bool_status = true;
    if(root1->data!=root2->data){
        return false;
    }

    else if(root1->children.size()!=root2->children.size()){
        return false;
    }
    else{
        for(int i=0; i<root1->children.size(); i++){
          if(!struct_equall(root1->children[i],root2->children[i])){
        return false;
          }
        }
    }

    return bool_status;
    
}

int main()
{   treenode<int> * root1 = takeinput_levelWise();
    treenode<int> * root2 = takeinput_levelWise();
    if(struct_equall(root1,root2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    //cout<<max_childSum(root).data;
    return 0;
}