#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

void print(node * head){
    while(head->next!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{   node * n1 = new node(16);
    node * head = n1;
    node * n2 = new node(25);
    node * n3 = new node(36);
    node * n4 = new node(49);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;

    print(head);
    return 0;
}