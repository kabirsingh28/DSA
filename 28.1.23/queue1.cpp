#include<bits/stdc++.h>
using namespace std;
#include "QueueClass.h"

int main()
{   
    Queue<int> q(6);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(100);
    
    cout<<q.front()<<endl; //10
    cout<<q.getsize()<<endl; //8
    cout<<q.dequeue()<<endl; //10
    cout<<q.dequeue()<<endl; //20
    cout<<q.dequeue()<<endl; //30
    cout<<q.dequeue()<<endl; //40
    cout<<q.dequeue()<<endl; //60
    cout<<q.dequeue()<<endl; //70
    cout<<q.getsize()<<endl; //2
    cout<<q.front()<<endl; //80
   
    return 0;
}