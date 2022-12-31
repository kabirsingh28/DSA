#include<bits/stdc++.h>
using namespace std;

void replace(char a[],int t=0){
    if(a[t]=='\0'||a[t+1]=='\0') return;
    replace(a,t+1);
    if(a[t]=='p' && a[t+1]=='i'){
        for(int i=strlen(a);i>=t+2;i--){
            a[i+2]=a[i];
        }
        a[t]='3';
        a[t+1]='.';
        a[t+2]='1';
        a[t+3]='4';
    }
    
}

int main()
{   char a[20];
    cin>>a;
    replace(a);
    cout<<a;
    return 0;
}