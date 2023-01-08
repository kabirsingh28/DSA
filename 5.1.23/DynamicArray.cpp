#include<bits/stdc++.h>
using namespace std;
#include "DynamicArrayClass.cpp"
int main()
{   dynamic d1;
    d1.add(56);
    d1.add(67);
    d1.add(78);
    d1.add(99);
    d1.add(35);
    d1.add(78);
    d1.add(789);
    d1.add(54);

    dynamic d2(d1);
    d2.add(0,23);
    
    dynamic d3;
    d3=d2;
    d2.add(1,200);
    d3.print();
    d2.print();
    return 0;
}