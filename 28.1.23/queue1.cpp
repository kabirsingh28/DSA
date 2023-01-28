#include<bits/stdc++.h>
using namespace std;
#include "QueueClass.cpp"

int main()
{   
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
   

    cout<<q.first()<<endl;
   


    return 0;
}