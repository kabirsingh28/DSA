#include<bits/stdc++.h>
using namespace std;



int main()
{   
    int n;
    cin>>n;
    int * p = new int[n];
    
    for(int i = 0; i < n; i++){
        cin>>p[i];
    }
    
    //find largest

    int L=p[0];
    for(int i = 1; i < n; i++){
        if(p[i]>L){
            L=p[i];
        }
    }
    
    cout<<L<<endl;
}

