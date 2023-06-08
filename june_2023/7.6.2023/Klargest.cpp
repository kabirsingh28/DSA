#include<bits/stdc++.h>
using namespace std;

vector<int> Klargest(int a[],int n, int k){
      priority_queue<int,vector<int>,greater<int>> pq;
      //above is min priority queue
      vector<int> output;
      for(int i=0; i<n; i++){
       if(i<k){
        pq.push(a[i]);
       }
       else if(i>=k){
        if(a[i]>pq.top()){
            pq.pop();
            pq.push(a[i]);
       }
      }
      }
      for(int i=0; i<k; i++){
        output.push_back(pq.top());
        pq.pop();
      }
      return output;
}

int main()
{   int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    vector<int> v = Klargest(a,n,k);
    for(int i=0; i<k; i++){
        cout<<v.at(i)<<endl;
    }
    return 0;
}