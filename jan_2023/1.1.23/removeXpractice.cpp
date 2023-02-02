#include<bits/stdc++.h>
using namespace std;

void removeX(char a[]){
   if(a[0]=='\0') return;
   if(a[0]!='x') removeX(a+1); 
   else{
    int i=1;
    for(;a[i]!='\0';i++){
        a[i-1]=a[i];
    }
    a[i-1]=a[i];
    removeX(a);
   }

}

int main()
{   char a[20];
    cin>>a;
    removeX(a);
    cout<<a;
    return 0;
}