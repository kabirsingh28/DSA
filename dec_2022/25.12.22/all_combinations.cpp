#include<bits/stdc++.h>
using namespace std;

void all_combinations(char a[], int n){
    for(int k=0; k<n; k++){
    for(int i = 0; i < n; i++){
        for(int j = k; j <= i; j++){
            cout<<a[j];
    }
    cout<<endl;
}
    }
}

int main(){
    char a[20];
    cin>>a;
    all_combinations(a,strlen(a));
}