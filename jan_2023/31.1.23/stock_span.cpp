#include<bits/stdc++.h>
using namespace std;
#include <queue>

//an efficient approch would be if we save the days in a stack

int main()
{   int flag=0;
    queue<int> q;
    queue<int> ans;
    int n;
    cin>>n;
    int data;
    while(n--){
        int count = 1;
        cin>>data;
        int k = ++flag;
        int x = data;
        q.push(data);
        while(k--){
            if(x>q.front()){
                count++;
            }
            else{
                break;
            }
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        ans.push(count);
    }

    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }


    return 0;
}