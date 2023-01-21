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

void print(node * head){
    node * t1 = head;
    while(t1!=NULL){
        cout<<t1->data<<" ";
        t1=t1->next;
    }
    cout<<endl;
}

node* merge_ll(node* a, node* b){
    if(!a) return b;
    if(!b) return a;
    if(a->data<b->data){
        a->next = merge_ll(a->next,b);
        return a;
    }
    else{
        b->next = merge_ll(a,b->next);
        return b;
    }
}

node* midElement(node * head){
    node * slow = head;
    node * fast = head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
}
    return slow;
}

node* merge_sort(node* a){
   if(a->next==NULL || a==NULL){
    return a;
   }
   node* mid = midElement(a);
   node* second_half = merge_sort(mid->next);
   mid->next = NULL;
   node* first_half = merge_sort(a);   
   return merge_ll(first_half,second_half);
}

int main()
{   node* a = take_input();
    a = merge_sort(a);
    print(a);
    return 0;
}