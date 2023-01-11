#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"
int main()
{   
    node n1(1);
    //node * head = &n1;
    node n2(2);
    n1.next = &n2; //now nodes are connected
    cout<<n1.data<<" "<<n2.data<<endl;
    //cout<<head->data<<endl;

    node * n3 = new node(10);
    node * head = n3;
    node * n4 = new node(20);
    n3->next=n4;
    cout<<head->data;
    return 0;
}