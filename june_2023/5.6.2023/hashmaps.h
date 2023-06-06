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

    void rehash(){
        mapNode<V>** temp = buckets;
        buckets = new mapNode<V>*[2*num_buckets];
        for(int i=0; i<2*num_buckets; i++){
            buckets[i]=NULL;
        }

        int oldBucketCount = num_buckets;
        num_buckets *=2;
        count = 0;
        
        //now we will triverse each and every element of
        //temp bucket array to be stored in new bucket array
        //of double the size

        for(int i=0; i<oldBucketCount; i++){
           mapNode<V>* head = temp[i];
           // now i will triverse on this corresponding ll
           while(head != NULL){
           string key = head->key;
           V value = head->value;
           insert(key, value);
           head = head->next; // to move along the linked list
           }
        }

        for(int i=0; i<oldBucketCount; i++){
             mapNode<V>* head = temp[i];
             delete head;
        }
        delete[] temp;
    }

    public:

    double getLoadFactor(){
        return (1.0*count)/num_buckets;
    }

    myMap(){
       count = 0;
       num_buckets = 5;
       buckets = new mapNode<V>*[num_buckets];
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
                head->value = value; //key already exsists, we just update the value
                return; 
        }
            head = head->next;
    }
      head = buckets[bucket_index];
      mapNode<V>* newNode = new mapNode<V>(key,value);
      newNode->next = head;
      buckets[bucket_index] = newNode; //now array stores the address of newNode as head 
      count++;
      double loadFactor = (1.0)*count/num_buckets;
      if(loadFactor > 0.7){
        rehash();
      }
    }
    
    V remove(string key){
         int bucket_index = getbucket_index(key);
         mapNode<V>* head = buckets[bucket_index];
         mapNode<V>* prev = NULL;
         while(head!=NULL){
            if(head->key == key){
                if(prev==NULL){
                  buckets[bucket_index] = head->next;
                }
                else{
                    prev->next = head->next;
                }
                int old_value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return old_value;
                
            }
            prev = head; // prev will get updated
            head=head->next;
         }
         return 0; // means coressponding key is not present
    }

    V getvalue(string key){
        int bucket_index = getbucket_index(key);
        mapNode<V>* head = buckets[bucket_index];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    int size(){
        return count;
    }

};