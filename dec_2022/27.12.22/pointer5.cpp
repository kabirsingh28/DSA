#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[10] = {28, 43, 98, 100};
//   cout<<a<<endl;
//   cout<<*(a+3)<<endl;
//   cout<<a[3]<<endl;
//   cout<<3[a]<<endl;
int * p = &a[3]; // extra memory gets allocated
cout<<sizeof(a)<<endl;
cout<<sizeof(p)<<endl;
cout<<a<<endl; // in case of 'a' no extra memory is allocated
cout<<&p<<endl;
cout<<&a<<endl;
p=p+1;
// a=a+1; //eror, 'a' cant be reassigned
cout<<*p<<endl;
p=a;
cout<<*p<<endl;
}