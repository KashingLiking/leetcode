struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==nullptr&&q==nullptr){
//             return true;
//         }
//         if(p==nullptr&&q!=nullptr){
//             return false;
//         }
//         if(p!=nullptr&&q==nullptr){
//             return false;
//         }
//         if(p->val==q->val){
//             if(p->left==nullptr&&p->right==nullptr&&q->left==nullptr&&q->right==nullptr){
//                 return true;
//             }
//             if(p->left==nullptr&&q->left==nullptr){
//                 if(p->right!=nullptr&&q->right!=nullptr){
//                     return isSameTree(p->right,q->right);
//                 }
//             }
//             if(p->right==nullptr&&q->right==nullptr){
//                 if(p->left!=nullptr&&q->left!=nullptr){
//                     return isSameTree(p->left,q->left);
//                 }
//             }
//             if(p->left!=nullptr&&q->left!=nullptr&&p->right!=nullptr&&q->right!=nullptr){
//                     return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};