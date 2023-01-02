#include<bits/stdc++.h>
using namespace std;

void replace(char a[], char x, char y){
    if(a[0]=='\0') return;
    if(a[0]==x){
        a[0]=y;
        replace(a+1,x,y);
    }
    else replace(a+1,x,y);
}

int main()
{   char a[20];
    cin>>a;
    char x,y;
    cin>>x>>y;
    replace(a,x,y);
    cout<<a;
    return 0;
}