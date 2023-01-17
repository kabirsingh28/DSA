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

int get_index(int x, node * head){
    node * temp = head;
    int count = 0;
    while(temp->data!=x&&temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
    return -1;
    }
    return count;
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

node* AppendLastNtoFirst(int x,node * head){
   node * temp = head;
   int count = 0;
   if(size(head)==x){
    return head;
   }
   while(count!=(size(head)-x-1)){
    temp=temp->next;
    count++;
   }
   node * temp2 = temp->next;
   while(temp2->next!=NULL){
    temp2=temp2->next;
   }
   temp2->next = head;
   head = temp-> next;
   temp->next = NULL;
   return head;
}

void Eliminate_duplicate(node * head){
    if(head==NULL || head->next==NULL){
        return;
    }
    node * t1 = head;
    node * t2 = head->next;    
    while(t2!=NULL){
        if(t1->data==t2->data){
            t2=t2->next; // removig links
        }
        else{
        t1->next=t2; // connecting t1 with t2
        t1=t1->next;
        t2=t2->next;
        }
    }
    t1->next=t2;    
}

//  void print_reverse(node * head){
//   int t = 1;
//   node * temp = head;
//   while(t!=size(head)){
     
//      int k = size(head)-t;
//      while(k--){
//         temp=temp->next;
//      }
//      cout<<temp->data<<" ";
//      t++;
//      temp = head;
//   }
//   cout<<temp->data<<" ";
// }
// above code is correct but time complexity is high i.e n^2

void print_reverse(node * head){
    if(head==NULL){
        return;
    }
    print_reverse(head->next);
    cout<<head->data<<" ";
}

int main()
{   node * head = take_input();
    // int x;
    // cin>>x;
    //cout<<get_index(x,head);
    //head = AppendLastNtoFirst(x,head);
    //Eliminate_duplicate(head);
    print_reverse(head);
    return 0;
}