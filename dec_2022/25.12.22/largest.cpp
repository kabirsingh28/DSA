#include<bits/stdc++.h>
using namespace std;

void input_b(int b[][20],int r, int c){
for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>b[i][j];
        }
    }
}

void largest(int a[],int b[][20],int r,int c){
    //rows
    for(int i=0; i<r; i++){
        int ans=0;
        for(int j=0; j<c; j++){
        ans+=b[i][j];
    }
    a[i]=ans;
}
    //column
    for(int i=0; i<c; i++){
        int ans=0;
        for(int j=0; j<r; j++){
        ans+=b[j][i];
    }
    a[r+i]=ans;
}
}

void largest_inA(int a[],int r, int size){
    int L=a[0],index;
    for(int i=1; i<size; i++){
        if(a[i]>L){
          L=a[i];
          index=i;
        }
    }
        if(index<=r){
            cout<<"row: "<<index<<", sum: "<< L;
        }
        else{
            cout<<"column: "<<index-r <<", sum: "<< L;
        }

    

}

int main(){
    int test;
    cin >> test;
    while(test--){
        int b[20][20];
        int n,m;
        cin>>n>>m;
        input_b(b,n,m);
        int a[50];
        largest(a,b,n,m);
        largest_inA(a,n,n+m);
                
    }
}