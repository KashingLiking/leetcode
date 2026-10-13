#include<iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*,Node*>map;
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        if(!map.count(node)){
            Node* clone = new Node(node->val);
            map[node] = clone;
        }
        for(Node* neighbor:node->neighbors){
            if(map.count(neighbor)){
                map[node]->neighbors.push_back(map[neighbor]);
            }else{
                map[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return map[node];
    }
};