#include<iostream>
using namespace std;

#include<unordered_set>

class Trie {
public:
    unordered_set<string>map;
    Trie() {
        map.clear();
    }
    
    void insert(string word) {
        map.insert(word);
    }
    
    bool search(string word) {
        if(map.count(word)){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for(string str : map){
            if((str.size()>=prefix.size())&&(str.substr(0,prefix.size())==prefix)){
                return true;
            }
        }
        return false;
    }
};
