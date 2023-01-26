#include<bits/stdc++.h>
using namespace std;
#include "PairClass.cpp"
#include "TripletClass.cpp"

int main()
{   

    //triplet using pair class
    Pair<int,Pair<double,double>> t1;
    t1.setX(28);
    Pair<double,double> p1;//defining pair p1 so it can be passed by t1 while setting y pair
    p1.setX(3.14);
    p1.setY(0.00159);
    t1.setY(p1);//only a pair can be passed 

    cout<<t1.getX()<<" "<<t1.getY().getX()<<" "<<t1.getY().getY()<<endl;

    // Pair<int,char> p1; // x is of int type and y is of char type
    // p1.setX(12); //x=12
    // p1.setY('A'); //y='A'
    // cout<<p1.getX()<<" "<<p1.getY();

    // triplet<int,double,char> t1;
    // t1.x = 28;
    // t1.y = 3.1415926;
    // t1.z = 'Q';
    // cout<<t1.x<<" "<<t1.y<<" "<<t1.z<<endl;
    // Pair<int> p1;
    // Pair<double> p2;

    // p1.setX(10.5);
    // p1.setY(20);
    // cout<<p1.getX()<<" "<<p1.getY()<<endl;

    // p2.setX(10.5);
    // p2.setY(3.14);
    // cout<<p2.getX()<<" "<<p2.getY()<<endl;

    return 0;
}