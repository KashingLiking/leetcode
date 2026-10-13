#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*>nodes;
        int res = 0;
        if(root==nullptr){
            return res;
        }
        nodes.push(root);
        while(!nodes.empty()){
            int size = nodes.size();
            for(int i = 0;i<size;i++){
                TreeNode* cur = nodes.front();
                if(cur->left!=nullptr){
                    nodes.push(cur->left);
                }
                if(cur->right!=nullptr){
                    nodes.push(cur->right);
                }
                nodes.pop();
            }
            res+=size;
        }
        return res;
    }
};