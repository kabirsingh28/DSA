#include<bits/stdc++.h>
using namespace std;
int size(char a[]){
    int flag=0,i=0;
    while(a[i]!='\0'){
        flag++;
        i++;
    }
    return flag;
}
int palindrome(char a[], int size){
int i=0,t=size/2;
while(i!=t){
if(a[i]!=a[size-1]){
    return 0;
}
i++;
size--;
}
if(i==t){
    return 1;
    
}
}

int main(){
    char a[10];
    cin>>a;

    if(palindrome(a,size(a))==1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}