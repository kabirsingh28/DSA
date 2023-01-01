#include<bits/stdc++.h>
using namespace std;

void removeX(char a[],int i=0,int t=0){
    if(a[t]!='x'||a[t]=='\0'){
        a[i]=a[t];
        i++;
    }
    
    if(a[t]=='\0') return;
    removeX(a,i,t+1);
}

int main()
{   char a[20];
    cin >> a;
    removeX(a);
    cout<<a;
    return 0;
}