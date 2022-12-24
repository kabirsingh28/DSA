#include<bits/stdc++.h>
using namespace std;

int length_ofstr(char a[]){
int flag=0,i=0;;
while(a[i]!='\0'){
 flag++;
 i++;
}
return flag;
}

int main(){
    char a[10];
    cin>>a;
    cout<<length_ofstr(a);
}