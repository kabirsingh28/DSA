#include<bits/stdc++.h>
using namespace std;

string print(int a) {
    switch(a){
        case 1:
        return("one");
        break;
        case 2:
        return("two");
        break;
        default:
        return("not in range");
        break;
        }

    }


int main(){
    int n;
    cin >> n ;
    cout<<print(n);
}