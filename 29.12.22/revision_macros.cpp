#include<bits/stdc++.h>
using namespace std;

#define pi 3.1415926

int main()
{
    int * p = new int;
    cout<<"enter radius"<<endl;
    cin>>*p;
    cout<<"area of circle is: "<<pi*(*p)*(*p)<<endl;
    
    delete p;
    return 0;
}