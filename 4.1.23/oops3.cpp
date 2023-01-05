#include<bits/stdc++.h>
using namespace std;
#include "oops1.cpp"

int main()
{   students s1;
    cout<<s1.getage()<<endl;
    
    students * s3 = new students();
    cout<<(*s3).getage()<<endl;
    cout<<s3->getage()<<endl;
    
    return 0;
}