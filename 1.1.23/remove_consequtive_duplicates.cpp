#include<bits/stdc++.h>
using namespace std;

void rcd(char a[]){
    if(a[0]=='\0') return;
    if(a[0]==a[1]){
        for(int i=0; i<strlen(a); i++){
            a[i]=a[i+1];
        }
        rcd(a);
    }
    else rcd(a+1);
}

int main()
{   char a[20];
    cin >> a;
    rcd(a);
    cout << a;
    return 0;
}