#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr){
            return root;
        }
        queue<Node*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int size = nodes.size();
            Node* prev = nullptr;
            for(int i = 0;i<size;i++){
                Node* cur = nodes.front();
                if(prev!=nullptr){
                    prev->next = cur;
                }
                prev = cur;
                if(prev->left!=nullptr){
                    nodes.push(prev->left);
                }
                if(prev->right!=nullptr){
                    nodes.push(prev->right);
                }
                nodes.pop();
            }
            prev->next = nullptr;
        }
        return root;
    }
};