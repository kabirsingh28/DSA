#include<bits/stdc++.h>
using namespace std;
#include "oops6.cpp"

int main()
{   
    //student s1; // interpreted as s1.student() => student() is called constructor
    //student s1(28);// interpreted as s1.student(28)
    //s1.dispaly();
    // student * a = new student(); // interpreted as (*a).student(46) or a->student(46)
    // a->dispaly();

    student * b = new student(23,67);
    b->dispaly();
    
    student * a = new student();
    a->dispaly(); 
    return 0;
}