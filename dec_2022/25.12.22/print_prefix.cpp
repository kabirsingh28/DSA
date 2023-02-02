#include<bits/stdc++.h>
using namespace std;

void print_prefix(char a[], int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<=i; j++){
            cout<<a[j];
        }
        cout<<"\n";
}
}

int main(){
    char a[20];
    cin>>a;
    print_prefix(a,strlen(a));
}