#include<bits/stdc++.h>
using namespace std;
#include "shallow_and_deepcopyClass.cpp"

int main()
{   char name[]="kabir"; 
    student s1(28,name);
    s1.show();
    
    name[4]='s';
    student s2(24,name);
    s2.show();
    s1.show();
    
    return 0;
}