#include<bits/stdc++.h>
using namespace std;

int to_integer(char a[],int size){
   if(size==0) return 0;
   int b = a[0]; //implicit typecasting
   b-=48;
   return b*pow(10,size-1) + to_integer(a+1,size-1);
}

int main()
{   char a[20];
    cin >> a;
    cout<<to_integer(a,strlen(a));
    return 0;
}  