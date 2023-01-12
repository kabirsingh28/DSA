#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

node* takeinput(){
    int data;
    cin>>data;
    node * head = NULL;
    
    while(data!=-1){
        node * n = new node(data);
        if(head==NULL){
            head=n; // means head is pointing to 1st node
        }
        //to link each element
        else{
            node * temp =head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=n;

        }
        cin>>data;
    }
    return head;
}

node* takeinput_better(){
    int data;
    cin>>data;
    node * head = NULL;
    node * tail = NULL;
    while(data!=-1){
        node * n = new node(data);
        if(head==NULL){
            head=n; // means head is pointing to 1st node
            tail=n; // i.e for the first element both tail and head points to 
        }
        //to link each element
        else{
           tail->next = n;
           tail=tail->next;//now value of tail gets updated with every new element added
        }
        cin>>data;
    }
    return head;
}


void print(node * head){
    node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int count(node * head){
    int count = 0;
    node * temp = head;
    while(temp!=NULL){
       temp=temp->next;
       count++;
    }
    return count;
}

int nthnode(int i, node * head){
    int count = 0;
    node * temp = head;
    while(temp!=NULL){
       temp=temp->next;
       count++;
       if(i==count){
        return temp->data;
       }
    }
    return -1;
}

node* insert(int i, int value, node * head){
    int index=0;
    node * temp = head;
    node * newNode = new node(value);

    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    while(temp!=NULL&&index<=i-1){
        temp=temp->next;
        index++;
    }
         if(temp!=NULL){
          node * old=temp->next;
          temp->next = newNode;
          newNode->next = old;
         }
return head;
    }

int main()
{   node * head = takeinput_better();
    print(head);
    //cout<<count(head);
    int i,value;
    cin>>i>>value;
    //cout<<nthnode(i,head);
    head = insert(i,value,head);
    print(head);
    return 0;
}