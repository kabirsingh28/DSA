#include<bits/stdc++.h>
using namespace std;
#include "ComplexNumberClass.cpp"
int main()
{  int r1,i1,r2,i2;
   cin>>r1>>i1;
   cin>>r2>>i2;
   complexnumber c1(r1,i1);
   complexnumber c2(r2,i2);

   int choice;
   cin >> choice;
   if (choice==1){
    c1.plus(c2);
    c1.print();
   }
   else if(choice==2){
    c1.multiply(c2);
    c1.print();
   }
    return 0;
}