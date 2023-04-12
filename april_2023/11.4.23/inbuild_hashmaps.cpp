#include<bits/stdc++.h>
using namespace std;
int main()
{   unordered_map<string,int> myMap;
    pair<string,int> p("kabir",28);
    myMap.insert(p);
    myMap["singh"] = 2;
    cout<<myMap["kabir"]<<endl;
    cout<<myMap.at("singh")<<endl;
    cout<<myMap["hanspal"]<<endl;
    cout<<myMap["ramghariya"]<<endl;
    //cout<<myMap.at("kala-ka")<<endl;
    cout<<myMap.count("singh")<<endl;
    if(myMap.count("kabir")) cout<<"exsists"<<endl;
    cout<<myMap.size();
    myMap.erase("kabir");   
    if(myMap.count("kabir")) cout<<"exsists"<<endl;

    return 0;
}