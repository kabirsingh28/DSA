#include<bits/stdc++.h>
using namespace std;
#include <stack>

int main()
{   stack<int> index;
    int n;
    cin>>n;
    int * price = new int[n];
    int * stock_span = new int[n];
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    
    index.push(0);
    stock_span[0]=1;
    for(int i=1; i<n; i++){
        while(!index.empty()&&price[i]>price[index.top()]){
            index.pop(); // pop all indices untill the while statement becomes true
        }
        if(index.empty()){
            stock_span[i] = i+1;
        }
        else{
            stock_span[i] = i-index.top();
        }
        index.push(i);
    }

    for(int i=0; i<n; i++){
        cout<<stock_span[i]<<" ";
    }

    return 0;
}