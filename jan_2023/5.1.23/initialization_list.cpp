#include<bits/stdc++.h>
using namespace std;
#include "initialization_listClass.cpp"
int main()
{   student s1(77,28); //error, can't initialize a const variable with garbage value
    s1.print();
    s1.x=s1.rollno;
    s1.print();
    return 0;
}