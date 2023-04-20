#include <bits/stdc++.h>
template <typename V>
class mapNode{
    public:
    string key;
    V value;
    mapNode* next;

    mapNode(string key, V value){
         this->key = key;
         this->value = value;
         next = NULL;
    }

    ~mapNode(){
        delete next;
    }

};

template <typename V>
class myMap{
    mapNode<V>** buckets;
    int count;
    int num_buckets;

    int getbucket_index(string key){
        int hashcode = 0;
        current_coeff = 1;
        
     }
    public:
    myMap(){
       count = 0;
       num_buckets = 5;
       buckets = new mapNode<V>**[num_buckets];
       for(int i=0; i<num_buckets; i++){
        buckets[i] = NULL;
       }
    }

    ~myMap(){
        for(int i=0; i<num_buckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    void insert(string key, V value){
        int bucket_index = getbucket_index(key);
    }

};