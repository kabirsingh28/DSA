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
    node * t1 = head;
    int count = 0;
    while(t1->data!=x&&t1->next!=NULL){
        t1=t1->next;
        count++;
    }
    if(t1->next==NULL){
    return -1;
    }
    return count;
}

void print(node * head){
    node * t1 = head;
    while(t1!=NULL){
        cout<<t1->data<<" ";
        t1=t1->next;
    }
    cout<<endl;
}

int size(node * head){
    int count = 0;
    node * t1 = head;
    while(t1!=NULL){
       t1=t1->next;
       count++;
    }
    return count;
}

node* AppendLastNtoFirst(int x,node * head){
   node * t1 = head;
   int count = 0;
   if(size(head)==x){
    return head;
   }
   while(count!=(size(head)-x-1)){
    t1=t1->next;
    count++;
   }
   node * temp2 = t1->next;
   while(temp2->next!=NULL){
    temp2=temp2->next;
   }
   temp2->next = head;
   head = t1-> next;
   t1->next = NULL;
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
//   node * t1 = head;
//   while(t!=size(head)){
     
//      int k = size(head)-t;
//      while(k--){
//         t1=t1->next;
//      }
//      cout<<t1->data<<" ";
//      t++;
//      t1 = head;
//   }
//   cout<<t1->data<<" ";
// }
// above code is correct but time complexity is high i.e n^2

void print_reverse(node * head){
    if(head==NULL){
        return;
    }
    print_reverse(head->next);
    cout<<head->data<<" ";
}

node* reverse_ll(node * head){
    if(!head || !(head->next)) return head;
    node * temp = reverse_ll(head->next);//called recursion on the rest of the linked list expcept the first node
    head->next->next = head; // attached the first node at the last,node 2 is common to temp and head
    head->next = NULL;
    return temp;
}

int compare_ll(node * t1, node * t2){
    int flag = 0;
    while(t1!=NULL){
     if(t1->data!=t2->data){
        flag++;
     }
     t1=t1->next;
     t2=t2->next;
    }
    if(flag==0) return 1;
    else return 0;
}

int CheckPalindrome(node * head){
    node * t1 = head;
    int k = size(t1)/2 - 1;
    while(k--){
       t1=t1->next;
    }
    node * t2 = t1->next;
    t1->next=NULL;
    t2 = reverse_ll(t2);
    return compare_ll(head,t2);
}

int main()
{   node * head = take_input();
    // int x;
    // cin>>x;
    //cout<<get_index(x,head);
    //head = AppendLastNtoFirst(x,head);
    //Eliminate_duplicate(head);
    //print_reverse(head);
    cout<<CheckPalindrome(head);
    return 0;
}