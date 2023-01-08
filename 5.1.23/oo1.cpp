#include<bits/stdc++.h>
using namespace std;
#include "operator_overloading.cpp"
int main(){
// {   fraction f1(28,4); 
//     fraction f2(36,6);
//     fraction f4 = f1 + f2;
//     fraction f5 = f1*f2;
//     f4.print();
//     f5.print();         
//     if(f1==f5){
//         cout<<"same";
//     }
//     else{
//         cout<<"not same";
//     }
//     return 0;

    //    fraction f6(10,2);
    //    fraction f7(15,4);
    //    ++f6;
    //    ++f7;
    //    f6.print();
    //    f7.print();
    // fraction f8 = ++(++f6); // ++f6 is being stored in the temporary buffer x 
                               //and ++x is being assinged to f8
                               //we have to return ++f6 by reference so no tempory buffer has to be involved
    //    ++f6;
    //    f6.print();
    //    f8.print();

    //    fraction f9 = f7++;
    //    f7.print();
    //    f9.print();
          fraction f10(28,7);
          fraction f11(81,9);
          (f10+=f11)+=f11;
          f10.print();
          f11.print();
}