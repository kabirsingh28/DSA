#include<bits/stdc++.h>
using namespace std;
#include "hashmaps.h"
int main()
{   myMap<int> map;
    for(int i=0; i<10; i++){
        char c = '0' + i;
        string key = "kab";
        key = key + c;
        int value = i + 1;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<endl;
    }
    cout<<map.size()<<endl;
    map.remove("kab0");
    map.remove("kab4");

     for(int i=0; i<10; i++){
        char c = '0' + i;
        string key = "kab";
        key = key + c;
        cout<<key<<": "<<map.getvalue(key)<<endl;
    }
    cout<<map.size()<<endl;

    
    return 0;
}