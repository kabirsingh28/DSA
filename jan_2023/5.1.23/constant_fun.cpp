#include<bits/stdc++.h>
using namespace std;
#include "constant_funClass.cpp"
int main()
{   const fraction f3(22,4); //constant objects can only call constant functions i.e they can' make
                             //changes in the current object
    cout<<f3.getnum()<<" "<<f3.getdeno()<<endl;
    // f3.setdino(55); => error
    f3.print(); //print is called only when its marked as constant 
    return 0;
}