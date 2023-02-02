#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

node* take_input(){
    int data;
    cin>>data;
    node * head = NULL;
    while (data!=-1)
    {  node * newNode = new node(data); // this->data=data and next = NULL
       if(head==NULL){
        head=newNode;
       }
       else{
        node * temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
       }
       cin>>data;
    }
    return head;//will be returning a pionter to the first element of the linked list so created
    
}

node* take_input_better(){
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

void print(node * head){
    node * temp = head;
    while(temp!=NULL){
     cout<<temp->data<<" ";
     temp=temp->next;
    }
    cout<<endl;
}

int size(node * head){
    int count = 0;
    node * temp = head;
    while(temp!=NULL){
       temp=temp->next;
       count++;
    }
    return count;
}

int element(int i, node * head){
    int count = 0;
    node * temp = head;
    while(count<=i-1){
        temp=temp->next; //triversing
        count++;
    }
    return temp->data;
}

node* insert(int i, int value, node * head){
    int count = 0;
    node * temp = head;
    if(i==0){
        node * newNode = new node(value);
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp!=NULL&&count<i-1){
        temp=temp->next; //triversing
        count++;
    }
    if(temp!=NULL){
    node * old_address = temp->next;
    node * newNode = new node(value);
    temp->next = newNode;
    newNode->next = old_address;
    }
    return head;
}


node* delete_node(int i, node * head){
    int count = 0;
    node * temp = head;
    if(i==0){
        head = temp->next;
        return head;
    }
    while(temp!=NULL&&count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
    node * nodeBefore = temp->next;
    node * temp1 = nodeBefore->next;
    temp->next = temp1;
    }
    return head;
}

int main()
{   node * head = take_input_better();//take input is a function whose ouput will point to head of linked list
    print(head);
    // int i,value;
    // cin>>i>>value;
    // node * head1 = insert(i,value,head);
    // print(head1);
    int i;
    cin>>i;
    node * head1 = delete_node(i,head);
    print(head1);
    return 0;

}