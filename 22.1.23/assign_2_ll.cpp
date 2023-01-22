#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

node* take_input(){
    int data;
    cin>>data;
    node * head = NULL;
    node * tail = NULL;
    while(data!=-1){
        node * newNode = new node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next = newNode;
            tail=tail->next;
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

int return_index(int x, node * head){
    node * temp = head;
    int count = 0;
    while(temp->data!=x){
        temp=temp->next;
        if(temp==NULL){
            return -1;
        }
        count++;
    }
    
        return count;
}

node* even_odd(node * head){
    node * temp = head;
    node * p1h = NULL;
    node * p2h = NULL;
    node * p1t = NULL;
    node * p2t = NULL;
    int flag_odd=0;
    int flag_even=0;
    while(temp!=NULL){
        if(temp->data%2==0){
            flag_even++;
            if(p2h==NULL){
                p2h=temp;
                p2t=temp;
                
            }
            else{
                p2t->next=temp;
                p2t=temp;
                
            }
        }
        else{
            flag_odd++;
            if(p1h==NULL){
                p1h=temp;
                p1t=temp;
                
            }
            else{
                p1t->next=temp;
                p1t=temp;
                
            }
        }
        temp=temp->next;
    }
    if(flag_odd==0){
        return p2h;
    }
    else if(flag_even==0){
        return p1h;
    }
    p1t->next=NULL;
    p2t->next=NULL;
    if(head->data%2==0){
        p2t->next=p1h;
        return p2h;
    }
    else{
        p1t->next=p2h;
        return p1h;
    }
    
}

int main()
{   node * head = take_input();
    // int x;
    // cin>>x;
    // cout<<return_index(x,head);
    head = even_odd(head);
    print(head);
    return 0;
}