#include<bits/stdc++.h>
using namespace std;
int main()
{   unordered_map<string,int> map;
    // map["kabir"] = 1;
    // map["kabir1"] = 2;
    // map["kabir2"] = 3;
    // map["kabir3"] = 4;
    // map["kabir4"] = 5;
    // map["kabir5"] = 6;
    // map["kabir6"] = 7;

    // unordered_map<string,int>::iterator it = map.find("kabir3");
    // map.erase(it);
    // cout<<it->first<<" "<<it->second;

    // unordered_map<string,int>::iterator it;
    // it = map.begin();
    // while(it!=map.end()){
    //     cout<<"key: "<<it->first<<" value: "<<it->second<<endl;
    //     it++;
    // }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    vector<int>::iterator itv = v.begin();
    v.erase(itv+2,itv+5);
    while(itv!=v.end()){
        cout<<*itv<<endl;
        itv++;
    }




    return 0;
}