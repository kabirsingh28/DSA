#include<bits/stdc++.h>
using namespace std;
#include "oops11.cpp"
int main()
{   student a(23,46);
    student b=a; // copy constructor is called rather than copy assignment operator
    b.show();
    return 0;
}