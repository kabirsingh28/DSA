#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>& dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = f(n-1,dp)+ f(n-2,dp);
}

int main()
{   int n;
    cin>>n;
    //vector<int> dp(n+1,-1);
    // n+1 is the size of max size of sub problem
    //cout<<f(n,dp);
    int prev2 = 0;
    int prev = 1;
    int curi;
    for(int i=2; i<=n; i++){
      curi = prev + prev2;
      prev2 = prev;
      prev = curi;
    }

    cout<<prev;
      
    return 0;
}