#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

void print(node * head){
    node * temp = head;
    while(temp!=NULL){
     cout<<temp->data<<" ";
     temp=temp->next;
    }
    cout<<endl;
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

int count(node * head){
    node * temp = head;
    if(temp->next==NULL){
        return 1;
    }
    temp = temp->next;
    return 1 + count(temp);
}

node* insert(int i, node * head,int value){
    
    if(i==0 || head == NULL){
        node * newNode = new node(value);
        newNode->next = head;
        head = newNode;
    }
    else{
    head->next = insert(i-1,head->next,value);
    }
    return head;
        

}

node* deleteRecursive(int i, node* head){
    if(i>=count(head)){
         return head;
    }
    if(i==0){
        head = head->next;
    }
    else{
     head->next = deleteRecursive(i-1,head->next);
    }
    return head;
}


int main()
{   node * head = take_input_better();
    print(head);
    cout<<count(head)<<endl;
    int i;
    cin>>i;
    //head= insert(i,head,value);
    head = deleteRecursive(i,head);
    print(head);

    return 0;
}