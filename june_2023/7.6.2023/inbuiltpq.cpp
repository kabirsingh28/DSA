#include<bits/stdc++.h>
using namespace std;
int main()
{   priority_queue<int> pq;

    pq.push(25);
    pq.push(240);
    pq.push(45);
    pq.push(95);
    pq.push(71);
    pq.push(36);

    cout<<"size: "<<pq.size()<<endl;
    cout<<"top : "<<pq.top()<<endl;

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
} 