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

void print_reverse(node * head){
    if(head==NULL){
        return;
    }
    print_reverse(head->next);
    cout<<head->data<<" ";
}

int midElement(node * head){
    node * slow = head;
    node * fast = head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
}
    return slow->data;
}

node* merge(node * head1, node * head2){
    node * h1 = head1;
    node * h2 = head2;
    node * fh = NULL;
    node * ft = NULL;
    while(h1!=NULL&&h2!=NULL){
        if(h1->data<h2->data){
           if(fh==NULL){
            fh=h1;
            ft=h1;
           }
            ft->next=h1;
            ft=h1;
            h1=h1->next;          
        }
        else{
            if(fh==NULL){
            fh=h2;
            ft=h2;
           }
           ft->next=h2; //linking
           ft=h2; //updating
           h2=h2->next; // triversing
        }
    }

    if(h1==NULL){
        ft->next = h2;
    }
    if(h2==NULL){
        ft->next = h1;
    }

    return fh;
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
{   node * head1 = take_input();
    node * head2 = take_input();
    //cout<<midElement(head);
    //head1 = merge(head1,head2);
    

    return 0;
}