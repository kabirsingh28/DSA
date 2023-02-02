#include<bits/stdc++.h>
using namespace std;

void input_b(int b[][20],int r, int c){
for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>b[i][j];
        }
    }
}

void wave_print(int b[][20],int r, int c){
    int x=1,t=0;
   for(int i=0; i<c; i++){
    x=pow(-1,i);
    int j;
    for(j=t; (j>=0)&&(j<r); j+=x){
          cout<<b[j][i]<<" ";
    }
    t=j-x;
}
}

int main(){
    int n,m;
    cin >> n >> m;
    int b[20][20];
    input_b(b,n,m);
    wave_print(b,n,m);
}