#include<bits/stdc++.h>
using namespace std;
#include "oops11.cpp"

int main()
{   student s1(22,45);
    s1.show();

    student s2(s1); // interpreted as s2.student(s1);
    s2.show();
    

    student * s3 = new student(28,56);
    cout<<"s3: "<<endl;
    s3->show();

    student s4(*s3); //static copy of an dynamic object
    cout<<"s4: "<<endl;
    s4.show();

    student * s5 =new student(*s3); //dynamic copy of an dynamic object
    cout<<"s5: "<<endl;
    s5->show();

    student * s6 =new student(s1); //dynamic copy of an static object
    cout<<"s6: "<<endl;
    s6->show();
}