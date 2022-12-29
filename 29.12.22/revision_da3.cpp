#include<bits/stdc++.h>
using namespace std;


int main()
{   
    int * p2 = new int;
    delete p2;
    int n;
    cin>>n;
    int * p = new int[n];  //created a array in the heap of size n
    delete [] p;  //deallocated the memory allocated to array
    return 0;
}