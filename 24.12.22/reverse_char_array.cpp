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

void reverse(char a[],int size){
    int i=0,t=size/2;
    while(i!=t){
        swap(a[i],a[size-1]);
        i++;
        size--;
    }
}

int main(){
    char a[20];
    cin.getline(a,20);
    reverse(a,size(a));
    cout<<a<<endl;
}