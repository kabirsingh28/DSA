#include<bits/stdc++.h>
using namespace std;
#include "polynomialClass.cpp"

int main() 
{   int N;
    cin>>N;

    int * degree_1 = new int[N];
    for(int i=0; i<N; i++){
        cin>>degree_1[i];
    }

    int * coeff_1 = new int[N];
    for(int i=0; i<N; i++){
        cin>>coeff_1[i];
    }
    
    polynomial p1(degree_1,coeff_1,degree_1[N-1]);

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
    
    polynomial p2(degree_2,coeff_2,degree_2[M-1]);
    
    cout<<"p1: ";
    p1.print();
    cout<<"p2: ";
    p2.print();
    polynomial p3 = p1+p2;
    p3.print();
    (p1+p2).print();
    
}