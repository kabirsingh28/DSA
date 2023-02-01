#include<bits/stdc++.h>
using namespace std;
#include <queue>

int main()
{   int flag=0;
    queue<int> q;
    int n;
    cin>>n;
    int data;
    while(n--){
        int count = 1;
        cin>>data;
        flag++;
        int x = data;
        q.push(data);
        while(flag--){
            if(x>q.front()){
                count++;
            }
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        cout<<count<<" ";
    }


    return 0;
}