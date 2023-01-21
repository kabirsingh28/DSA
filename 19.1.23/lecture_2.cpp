#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

class Pair{
    public:
    node * head;
    node * tail;
};

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



void print(node * head){
    node * t1 = head;
    while(t1!=NULL){
        cout<<t1->data<<" ";
        t1=t1->next;
    }
    cout<<endl;
}

node* reversell_1(node * head){
    if(!head || !head->next) return head;
    node * temp = reversell_1(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}

Pair reversell_better(node * head){
    if(!head || !head->next){//if only 1 or no element is present
       Pair ans;
       ans.head=head;
       ans.tail=head;
       return ans;

    }

    Pair smallans = reversell_better(head->next); //head and tail of samll reversed ll gets saved in smallans
    smallans.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallans.head;
    ans.tail=head;
    return ans;
}

node* reversell_2(node * head){
    return reversell_better(head).head;
}





int main()
{   node * head = take_input();
    node * head1 = take_input();
    node * head2 = merge_ll(head,head1);
    print(head2);

    
    

    return 0;
}


