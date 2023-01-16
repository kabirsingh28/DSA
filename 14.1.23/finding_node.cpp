#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

node* take_input(){
    int data;
    cin>>data;
    node * head = NULL;
    node * tail =NULL;
    while (data!=-1)
    {  node * newNode = new node(data); // this->data=data and next = NULL
       if(head==NULL){
        head=newNode;
        tail=newNode; //if only one node is created both haed and tail will be pointing to same node
       }
       else{
        tail->next=newNode;
        tail=tail->next;
       }
       cin>>data;
    }
    return head;//will be returning a pionter to the first element of the linked list so created
    
}

int return_index(int x, node * head){
    int count = 0;
    node * temp = head;
    while(temp->data!=x&&temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        return -1;
    }
    else{
    return count;
    }
    
}

int main()
{   node * head = take_input();
    int x;
    cin>>x;
    cout<<return_index(x,head)<<endl;
    return 0;
}