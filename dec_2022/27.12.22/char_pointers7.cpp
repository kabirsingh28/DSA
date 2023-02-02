#include<bits/stdc++.h>
using namespace std;

// int main(){
//     // int a[] = {0,1,2,3,4,5,6,7};
//     // char c[] = "abcdefg";

//     // // cout<<a<<" "<<c<<endl;
//     // char * b=&c[0];
//     // cout<<b<<" "<<*b;
//     char c = 'a';
//     char * p = &c;

//     cout<<c<<" "<<*p;

// }
// void fun(int a[]) {
//     cout << a[2] << " ";
// }

// int main() {
//     int a[] = {1, 2, 3, 4};
//     fun(a + 1);
//     cout << a[0];
// }
void square(int *p){
 int a = 10;
 p = &a;
 *p = (*p) * (*p);
}

int main(){
 int a = 10;
 square(&a);
 cout << a << endl;
}