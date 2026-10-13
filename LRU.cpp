// #include<iostream>
// using namespace std;

// class LRUCache {
// public:
//     int size = 0;
//     unordered_map<int,int>mp;
//     vector<int>pool;
//     LRUCache(int capacity) {
//         size = capacity;
//     }
    
//     int get(int key) {
//         if(mp.count(key)!=NULL){
//             for(int i = 0;i<pool.size();i++){
//                 if(pool[i]==key){
//                     pool.erase(pool.begin()+i);
//                     pool.push_back(key);
//                     break;
//                 }
//             }
//             return mp[key];
//         }else{
//             return -1;
//         }
//     }
    
//     void put(int key, int value) {
//         if(mp.count(key) != NULL){
//             mp[key] = value;
//             for(int i = 0;i<pool.size();i++){
//                 if(pool[i]==key){
//                     pool.erase(pool.begin()+i);
//                     pool.push_back(key);
//                     break;
//                 }
//             }
//         }else{
//             if(pool.size()==size){
//                 mp.erase(pool[0]);
//                 pool.erase(pool.begin());
//             }
//             pool.push_back(key);
//             mp[key] = value;
//         }
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */
#include<iostream>
#include <list>
#include<unordered_map>
#include <iterator>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int,int>>cache;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)==NULL){
            return -1;
        }
        auto it = mp[key];
        cache.splice(cache.end(),cache,it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)!=NULL){
            auto it = mp[key];
            it->second = value;
            cache.splice(cache.end(),cache,it);
            return;
        }
        if(cache.size()==capacity){
            auto oldest = cache.front();
            mp.erase(oldest.first);
            cache.pop_front();
        }
        cache.push_back({key,value});
        mp[key] = prev(cache.end());
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */