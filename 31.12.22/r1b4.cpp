#include<bits/stdc++.h>
using namespace std;

void pair_star(char a[], int t=0){
    if(a[t]=='\0' || a[t+1]=='\0') return;
    if(a[t]==a[t+1]){
        char c = a[t];
        for(int i=strlen(a); i>=t+2; i--){
           a[i+1]=a[i];
    }
    a[t]=c;
    a[t+1]='*';
    a[t+2]=c;
}
   pair_star(a, t+2);
}


int main()
{   char a[20];
    cin >> a;
    pair_star(a);
    cout<<a;
    return 0;
}