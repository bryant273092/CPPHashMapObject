#include "HashMap.hpp"
#include <string>
#include <math.h>
#include <iostream>
unsigned int default_function(const std::string& key){
    int f = 39;
    int hash = 0; 
    for (unsigned int i = 0 ; i < key.length() ; i++){
        hash = f * hash + int(key.at(i));
    }
   return hash;

}
HashMap::HashMap()
    : hashFunction{default_function}, buckets{new Node*[INITIAL_BUCKET_COUNT]}, bucket_size{INITIAL_BUCKET_COUNT}
{
    initiate_empty_bucket();
}

HashMap::HashMap(HashFunction hashFunction)
    :hashFunction{hashFunction}, buckets{new Node*[INITIAL_BUCKET_COUNT]}, bucket_size{INITIAL_BUCKET_COUNT}
{
    initiate_empty_bucket();
}
//The Big Three

HashMap::HashMap(const HashMap& hm)
: hashFunction{hm.hashFunction}, buckets{new Node*[hm.bucket_size]}, bucket_size{hm.bucket_size}, pair_count{hm.pair_count}
{
    initiate_empty_bucket();
    for(unsigned int index = 0; index < bucket_size ; index++){ //iterate through old buckets
        Node* current = hm.buckets[index];
        while(current != nullptr){  //iterate through old nodes
            Node* node_copy = new Node{current->key, current->value, buckets[index]};
            buckets[index] = node_copy; //add current node to new bucket list
            current = current->next;
        }
    }
}

HashMap::~HashMap(){
    for(unsigned int i = 0 ; i < bucket_size; i++){
        Node* current = buckets[i];
        if(current!=nullptr){
            while(current->next != nullptr){
                Node* temp = current->next;
                delete current;
                current = temp;

            }
            
        
        }
        delete current;

    }
    delete[] buckets;
}

HashMap& HashMap::operator=(const HashMap& hm){
    Node** new_buckets = new Node*[hm.bucketCount()];
    
    //initiate new bucket list
    for (unsigned int i = 0; i < hm.bucketCount(); i++)
    {
        new_buckets[i] = nullptr;
    }
    for(unsigned int index = 0; index < hm.bucketCount() ; index++){ //iterate through old buckets
        Node* current = hm.buckets[index];
        while(current != nullptr){  //iterate through old nodes
            Node* node_copy = new Node{current->key, current->value, new_buckets[index]};
            new_buckets[index] = node_copy; //add current node to new bucket list
            current = current->next;
        }
    }
    HashMap::~HashMap();
    bucket_size = hm.bucketCount();
    buckets = new_buckets; 
    return *this;  

}



void HashMap::add(const std::string& key, const std::string& value){
    //if key does not already exist
    
        //if load factor is greater that 0.8
        if(loadFactor() >= 0.8){
            increase_bucket_capacity();
        } 
        if (!contains(key))
            {
                //find bucket where new node should go
                int index = find_bucket(key);
                //initiate new node (which will be new head) with its 'next' variable holding
                //the old node head in bucket
                Node *new_head = new Node{key, value, buckets[index]};
                //make head node-pointer in bucket point to new node just added
                buckets[index] = new_head;
                pair_count++;
            } 
            
}
bool HashMap::remove(const std::string& key){
    if(contains(key)){
        int index = find_bucket(key);
        Node* current = buckets[index];
        if(current->key == key){
            Node* new_head = current->next;
            delete current;
            buckets[index] = new_head;
            pair_count--;
            return true;
            

        }
        Node* previous;
        while(current != nullptr){
            if (current->key == key){
                previous->next = current->next;
                delete current;
                pair_count--;
                return true;
            }else{
                previous = current;
                current = current->next;
            }
        }

    }
    return false;
}

std::string HashMap::value(const std::string& key) const{
    int index = find_bucket(key); 
    
    //iterate through bucket linked list nodes to find if key exists
    Node* current = buckets[index];
    while(  current != nullptr ){
        //If key is in bucket
        
        if (current->key == key){
            return current->value;
        }
        current = current->next;

    }
    return "";

}

unsigned int HashMap::size() const{
    return pair_count;
}


bool HashMap::contains(const std::string& key) const{
    //call find_bucket function to see what bucket it would go to
    int index = find_bucket(key); 
    //iterate through bucket linked list nodes to find if key exists
    Node* current = buckets[index];
    while(  current != nullptr ){
        //If key is in bucket
        
        if (current->key == key){
            return true;
        }
        current = current->next;

    }
    return false;
}

unsigned int HashMap::bucketCount() const{
    return bucket_size;
}

unsigned int HashMap::maxBucketSize() const{  
    unsigned int most_nodes= 0;
    for(unsigned int i = 0 ; i < bucket_size; i++){
        unsigned int node_count = 0; 
        Node* current = buckets[i];
        while(current != nullptr){
            node_count++;
            current = current->next;
        }
        if(node_count > most_nodes){
            most_nodes = node_count;
        }
    }
    

    return most_nodes;

}

//Custom: find the designated bucket for a particular key, returns index for bucket list
unsigned int HashMap::find_bucket(const std::string& key) const {
    return round((hashFunction(key) %  10)/10.0 * bucketCount());
    
}


double HashMap::loadFactor() const{
    return pair_count/(bucket_size * 1.0);
}


//Custom: increase bucket capacity and rehash all nodes
void HashMap::increase_bucket_capacity(){
    // temp size var
    int new_size = (bucket_size * 2) + 1;;
    Node** new_buckets = new Node*[new_size];
    //initiate new bucket list
    for (unsigned int i = 0; i < new_size; i++)
    {
        new_buckets[i] = nullptr;
    }
    //Rehash all existing nodes
    for(unsigned int index = 0; index < bucket_size ; index++){ //iterate through old buckets
        Node* current = buckets[index];
        while(current != nullptr){  //iterate through old nodes
            int new_index = round((hashFunction(current->key) %  10)/10.0 * new_size);
            Node* node_copy = new Node{current->key, current->value, new_buckets[new_index]};
            new_buckets[new_index] = node_copy; //add current node to new bucket list
            current = current->next;
        }
    }
    HashMap::~HashMap();
    bucket_size = new_size;
    buckets = new_buckets;   
       
}

//Custom: initiates current bucket list with nullptr object
void HashMap::initiate_empty_bucket(){
    for(unsigned int i = 0 ; i < bucket_size; i++){
        buckets[i] = nullptr;
    }
}

//Custom: Prints all key -> value pairs by bucket
void HashMap::printPairs(){
    for(unsigned int i = 0 ; i < bucket_size; i++){
        Node* current = buckets[i];
        std::cout << " In bucket: "<< i << std::endl;
        while(current != nullptr){
            std::cout << "          KEY: " << current->key << " VALUE: " << current->value <<std::endl;
            current = current->next;
        }
    }

}