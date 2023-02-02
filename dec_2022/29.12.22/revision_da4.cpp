#include<bits/stdc++.h>
using namespace std;
//intitialing 2d array in heap

int main()
{   int r,c;
    cin>>r>>c;
    int ** q = new int*[r]; // made an array of pointers, 
                            //each pointer pointing to the individual row of the array
    for(int i=0; i<r; i++){
        q[i] = new int[c];  //intializing each pointer in the array to another array of size c
        for(int j=0; j<c; j++){
            cin>>q[i][j];   // now taking input of every elemnt of array
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<q[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0; i<r; i++){
        delete [] q[i];   // deleting each of array
    }

    delete [] q; // deleting array of pointers
    
    return 0;
}