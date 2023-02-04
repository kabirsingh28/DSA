#include<bits/stdc++.h>
using namespace std;
#include <vector>

int main()
{   vector<int> v; //statically
    //vector<int> * vp = new vector<int>(); //dynamically
    for(int i=0; i<100; i++){
        cout<<v.capacity()<<endl;
        v.push_back(i+1);
        cout<<v.size()<<endl;
    }
    return 0;
}