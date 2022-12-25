#include<bits/stdc++.h>
using namespace std;

void input_array(int b[][5],int r, int c){
for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>b[i][j];
        }
    }
}

void output_array(int b[][5],int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int b[4][5];
    cout<<"no. of rows and columns: ";
    int r,c;
    cin >>r>>c;
    cout<<"input array: "<<"\n";
    input_array(b,r,c);
    output_array(b,r,c);


}