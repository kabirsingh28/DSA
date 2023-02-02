#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

void print(node * head){
    node * temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    
}

int main()
{   node n1(10);
    node * head = &n1;
    node n2(20);
    node n3(30);
    node n4(40);
    node n5(50);
    node n6(60);
    node n7(70);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    print(head);
    print(&n3);
    
    return 0;
}