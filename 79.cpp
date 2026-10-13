#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    vector<int>nodes;
    int sig = 0;
    BSTIterator(TreeNode* root) {
        nodes.clear();
        sig = 0;
        addelement(root);
    }
    
    int next() {
        sig++;
        return nodes[sig-1];
    }
    
    bool hasNext() {
        if(sig==nodes.size()){
            return false;
        }
        return true;
    }

    void addelement(TreeNode* root){
        if(root->left!=nullptr){
            addelement(root->left);
        }
        nodes.push_back(root->val);
        if(root->right!=nullptr){
            addelement(root->right);
        }
    }
};
