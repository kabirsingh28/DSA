map.erase(it,it+4);
    while(it!=map.end()){
        cout<<"key: "<<it->first<<", value: "<<it->second<<"\n";
        it++;