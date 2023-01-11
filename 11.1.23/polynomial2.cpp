#include<bits/stdc++.h>
using namespace std;
#include "polynomialClass2.cpp"
int main()
{    int N;
    cin>>N;

    int * degree_1 = new int[N];
    for(int i=0; i<N; i++){
        cin>>degree_1[i];
    }

    int * coeff_1 = new int[N];
    for(int i=0; i<N; i++){
        cin>>coeff_1[i];
    }
    
    polynomial p1;
    for(int i=0; i<N;i++){
        p1.setCoeff(degree_1[i],coeff_1[i]);
    }
    p1.print();

    int M;
    cin>>M;

    int * degree_2 = new int[M];
    for(int i=0; i<M; i++){
        cin>>degree_2[i];
    }

    int * coeff_2 = new int[M];
    for(int i=0; i<M; i++){
        cin>>coeff_2[i];
    }
    
    polynomial p2;
    for(int i=0; i<M;i++){
        p2.setCoeff(degree_2[i],coeff_2[i]);
    }
    
    polynomial p3 = p1+p2;
    cout<<"addition: ";
    p3.print();

    polynomial p4 = p1-p2;
    cout<<"substraction: ";
    p4.print();

    polynomial p5 = p1*p2;
    cout<<"multiplication: ";
    p5.print();

    
    return 0;
}