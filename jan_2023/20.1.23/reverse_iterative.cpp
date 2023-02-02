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

node* reverse_iterative(node * head){
    node* next = head->next;
    node* current = head;
    node* previous = NULL;
    while(current!=NULL){
        next = current->next; // saving the link into next
        current->next = previous; //new backwards link

        previous = current;
        current = next;
    }
    return previous;
}

void print(node * head){
    node * t1 = head;
    while(t1!=NULL){
        cout<<t1->data<<" ";
        t1=t1->next;
    }
    cout<<endl;
}

int main()
{   node * head = take_input();
    head = reverse_iterative(head);
    print(head);
    return 0;
}