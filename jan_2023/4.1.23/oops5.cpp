#include<bits/stdc++.h>
using namespace std;
#include "oops4.cpp"

int main()
{   student a;
    a.rollno = 12;
    a.setage(45);
    a.display();
    cout<<endl<<a.getage()<<endl;
    student * b = new student();
    b->rollno = 13;
    b->setage(28);
    b->display();
    return 0;
}