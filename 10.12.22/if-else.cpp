#include<bits/stdc++.h>
using namespace std;

string compare(int a, int b) {
    if(a>b){
        return("greater");
    }
    else if(a<b){
        return("less");
    }
    else{
        return("equal");
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    cout<<compare(n,m);
}