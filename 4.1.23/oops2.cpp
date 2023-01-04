#include<bits/stdc++.h>
using namespace std;
#include "oops1.cpp"


int main()
{   students s1;
    s1.rollno = 45;
    s1.age = 22;
    cout<<s1.age<<endl;
    

    students s2,s3;
    s2.age =56;
    s3.rollno = 45;
    cout<<s2.age<<" "<<s3.rollno<<" "<<s1.age<<" ";

    students * s4 = new students();
    (*s4).age =98;
    cout<<(*s4).age;





}