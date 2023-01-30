#include<bits/stdc++.h>
using namespace std;
#include <queue>

void reverse_queue(queue<int> &q){
    if(q.empty()||q.size()==1){
        return;
    }
    int x = q.front();
    q.pop();
    reverse_queue(q);
    q.push(x);
}

int main()
{   
    queue<int> q;
    int n;
    cin>>n;
    int data;
    while(n--){
        cin>>data;
        q.push(data);
    }

    reverse_queue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }


    return 0;
}