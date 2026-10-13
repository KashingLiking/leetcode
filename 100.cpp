#include<iostream>
using namespace std;

#include<unordered_set>

// class WordDictionary {
// public:
//     unordered_set<string>map;
//     WordDictionary() {
//         map.clear();
//     }
    
//     void addWord(string word) {
//         map.insert(word);
//     }
    
//     bool search(string word) {
//         for(string str:map){
//             if(str.size()==word.size()){
//                 for(int i = 0;i<str.size();i++){
//                     if(str[i]!=word[i]&&word[i]!='.'){
//                         break;
//                     }
//                     if(i==str.size()-1){
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };这种有点慢


struct TrieNode{
    bool isEnd;
    TrieNode* child[26];
    TrieNode()
    {
        isEnd = false;
        for(int i=0;i<26;i++)
            child[i]=nullptr;
    }
};


class WordDictionary {
public:
    TrieNode*root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int num = c - 'a';
            if(cur->child[num]==nullptr){
                cur->child[num] = new TrieNode();
            }
            cur = cur->child[num];
        }
        cur->isEnd = true;
    }
    
    bool dfs(string& word,int pos,TrieNode* cur){
        if(pos==word.size()){
            return cur->isEnd;
        }
        if(word[pos]=='.'){
            for(int i = 0;i<26;i++){
                if(cur->child[i]!=nullptr){
                    if(dfs(word,pos+1,cur->child[i])){
                        return true;
                    }
                }
            }
            return false;
        }
        if(cur->child[word[pos]-'a']!=nullptr){
            return dfs(word,pos+1,cur->child[word[pos]-'a']);
        }
        return false;
    }

    bool search(string word) {
        return dfs(word,0,root);
    }
};
