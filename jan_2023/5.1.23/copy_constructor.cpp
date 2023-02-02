#include<bits/stdc++.h>
using namespace std;
#include "copy_constructorclass.cpp"

int main()
{  char name[] ="kabir";
   student s1(22,name); //here name is not the entire string its the address of 1st element of "kabir" i.e k
   s1.print();

   student s2(s1); //copy constructor is called
   s2.name[0]='z';
   s1.print();// i.e only s1 should be kabis 22
   s2.print();// but s2 also comes out to be kabis 22 due to sahllow coping

    return 0;
}