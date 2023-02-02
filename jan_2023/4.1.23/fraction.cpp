#include<bits/stdc++.h>
using namespace std;
#include "fractionclass.cpp"

int main()
{   fraction f1(28,4);
    fraction f2(90,5);
    f1.print();
    f2.print();
    f1.add(f2);
    f1.print();
    cout<<"multiplication: "<<endl;
    f1.multiply(f2);
    f1.print();
    return 0;
}