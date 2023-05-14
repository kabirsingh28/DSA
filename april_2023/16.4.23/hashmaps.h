#include <bits/stdc++.h>
using namespace std;
 
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
        int current_coeff = 1;
        for(int i=key.size()-1; i>=0; i--){
            hashcode += current_coeff*key[i];
            hashcode%=num_buckets;
            current_coeff*=37;
            current_coeff%=num_buckets;
        }
        return hashcode%num_buckets;
        
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
        mapNode<V>* head = buckets[bucket_index];
        while(head!=NULL){
            if(head->key == key){
                head->value = value;
                return; 
        }
            head = head->next;
    }
      head = buckets[bucket_index];
      mapNode<V>* newNode = new mapNode<V> * (key,value);
      newNode->next = head;
      buckets[bucket_index] = newNode; //now array stores the address of newNode as head 
      count++;
    }
    
    V remove(string key){
         
    }


};