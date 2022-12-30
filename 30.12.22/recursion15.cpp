#include<bits/stdc++.h>
using namespace std;
 
bool f(char a[],int s){
    if(a[0]!=a[s-1]) return false;
    if(s==1||s==0) return true;
    f(a+1,s-2);

}

int main()
{   
   char a[]="racecar";
   int t=strlen(a);
   cout<<f(a,t);
}