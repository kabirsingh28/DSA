#include<bits/stdc++.h>
using namespace std;

void input_b(int b[][20],int r, int c){
for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>b[i][j];
        }
    }
}

void spiral_print(int b[][20],int r,int c){
    int cs=0,ce=c-1,rs=0,re=r-1;
    while((cs<=ce)&&(rs<=re)){
     for(int i=cs; i<=ce; i++){
        cout<<b[rs][i]<<" ";
     }
     rs++;
     for(int i=rs; i<=re; i++){
        cout<<b[i][ce]<<" ";
     }
     ce--;
     for(int i=ce; i>=cs; i--){
        cout<<b[re][i]<<" ";
     }
     re--;
     for(int i=re; i>=rs; i--){
        cout<<b[i][cs]<<" ";
     }
     cs++;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int b[20][20];
    input_b(b,n,m);
    spiral_print(b,n,m);
}