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

void reverse(char a[],int start, int end){
    int i=start,t=(start+end)/2;
    while(i!=t){
        swap(a[i],a[end-1]);
        i++;
        end--;
    }
}

void reverse_word(char a[],int size){
    int i=0,j=0;
    while(i<size){
    while((a[j]!=' ')&&(a[j]!='\0')){
        j++;
    }
    reverse(a,i,j);
    i=++j;
    }
}

int main(){
    char a[20];
    cin.getline(a,20);
    reverse(a,0,size(a));
    cout<<a<<endl;
    reverse_word(a,size(a));
    cout<<a<<endl;
}