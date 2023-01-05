#include<bits/stdc++.h>
using namespace std;
#include "oops11.cpp"

int main()
{   student s1(10,100);
    student s2(20,200);
    cout<<"s1: ";
    s1.show();
    cout<<"s2: ";
    s2.show();
    s2=s1; //copy assignment operator
    cout<<"s1: ";
    s1.show();
    cout<<"s2: ";
    s2.show();
    student * s3 = new student(78,83);
    s2=*s3;
    cout<<"s3: ";
    s3->show();
    cout<<"s2: ";
    s2.show();

    delete s3; //necessary to write delete s3; as to deallocate memory allocated to *s3 object,
               //special treatment cause its a pointer
    return 0;
}