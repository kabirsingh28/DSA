#include<bits/stdc++.h>
using namespace std;

void replace(char a[],int size,string ans=""){
    if(size==0) return;
    if(a[0]=='p'&&a[1]=='i'){
        cout<<"3.14";
        replace(a+2,size-2,ans);
    }
    else{
         cout<<a[0];
         replace(a+1,size-1,ans);
    }
    
}

int main()
{   char a[20];
    cin>>a;
    replace(a,strlen(a));
    return 0;
}