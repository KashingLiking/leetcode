#include<iostream>
using namespace std;

class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        res.clear();
        dfs(n,n,"");
        return res;
    }
    void dfs(int left,int right,string str){
        if(left==0&&right==0){
            res.push_back(str);
            return;
        }else if(left==0){
            dfs(left,right-1,str+')');
        }else{
            if(left==right){
                dfs(left-1,right,str+'(');
            }else{
                dfs(left-1,right,str+'(');
                dfs(left,right-1,str+')');
            }
        }
        return;
    }
};

// class Solution {
// public:
//     vector<string>res;
//     vector<string> generateParenthesis(int n) {
//         res.clear();
//         dfs(n,n,"");
//         return res;
//     }
//     void dfs(int left,int right,string str){
//         if(left==0){
//             for(int i = 0;i<right;i++){
//                 str+=')';
//             }
//             if(right!=0){
//                 res.push_back(str);
//             }

//             return;
//         }else{
//             string copy = str;
//             copy+='(';
//             left--;
//             if(left==0){
//                 dfs(left,right,copy);
//             }else{
//                 for(int i = 0;i<right-left+1;i++){
//                     dfs(left,right-i,copy);
//                     copy+=')';
//             }
//             }
            
//         }
//         return;
//     }
// };