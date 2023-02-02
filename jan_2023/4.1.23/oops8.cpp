#include<bits/stdc++.h>
using namespace std;
#include "oops9.cpp"
int main()
{   student s1(28);//s1.student(28) => memory block is allocated with some meomery address &s1 and constructor gets activated
    cout<<&s1<<endl;
    s1.show();

    student * abc = new student(45);
    cout<<abc<<endl;
    abc->show();
    return 0;
}