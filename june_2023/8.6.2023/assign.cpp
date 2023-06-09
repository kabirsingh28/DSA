#include<bits/stdc++.h>
using namespace std;

class triplet{
    int element;
    int arrayIndex;
    int elementIndex;
};

int checkMaxHeap(int a[],int n){
   for(int i=0; i<=(n-2)/2; i++){
    if(a[i]<a[2*i+1] && 2*i+2<n && a[i]<a[2*i+2]) return 0;
   }
   return 1;
}

int Kth_largest(int* a,int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0 ; i<n; i++){
       if(i<k) pq.push(a[i]);
       else{
        if(a[i]>pq.top()){
            pq.pop();
            pq.push(a[i]);            
        }
       }
    }
    return pq.top();
    
}

void runningMedian(int a[],int n){
    vector<int> output;
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
      
    max.push(a[0]);
    output.push_back(a[0]);
    for(int i=1; i<n; i++){
      
      if(a[i]>max.top()){
        min.push(a[i]);
        if(min.size()-max.size()>1){
            max.push(min.top());
            min.pop();
        }
      }
      else{
        max.push(a[i]);
        if(max.size()-min.size()>1){
            min.push(max.top());
            max.pop();
        }
    }

       if(max.size()<min.size()){
            output.push_back(min.top());
        }
        else if(max.size()>min.size()){
            output.push_back(max.top());
        }
        else{
            output.push_back((max.top()+min.top())/2);
        }

    }
    for(int i=0; i<n; i++){
        cout<<output.at(i)<<endl;
    }

}

int timeRequired(queue<pair<int,int>>& line,int n,int k){
    priority_queue<int> max;
    int time = 0;
    while(n--){
        max.push(line.front().first);
        line.push(line.front());
        line.pop();
    }
    while(1){
        if(line.front().first==max.top()){
            time++;
            max.pop();
        if(line.front().second==k) return time;
            line.pop();
        }
        else{
            line.push(line.front());
            line.pop();
        }
    }
    
}

int main()
{        
    // int n;
    // cin>>n;
    // queue<pair<int,int>> line;
    // for(int i=0; i<n; i++){
    //     pair<int,int> p;
    //     cin>>p.first;
    //     p.second = i;
    //     line.push(p);
    // }
    // int k; //index of my priority
    // cin>>k;

    // cout<<timeRequired(line,n,k);

    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0; i<n; i++){
    //     cin>>a[i];
    // }

    // runningMedian(a,n);

    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0; i<n; i++){
    //     cin>>a[i];
    // }
    // int k;
    // cin>>k;
    // cout<<Kth_largest(a,n,k);
    return 0;
}