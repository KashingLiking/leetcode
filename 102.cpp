#include<iostream>
using namespace std;

class Solution {
public:
    unordered_map<char,vector<string>>mp{
        {'2',{"a","b","c"}},
        {'3',{"d","e","f"}},
        {'4',{"g","h","i"}},
        {'5',{"j","k","l"}},
        {'6',{"m","n","o"}},
        {'7',{"p","q","r","s"}},
        {'8',{"t","u","v"}},
        {'9',{"w","x","y","z"}}
    };
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.size()==0){
            return res;
        }
        while(digits.size()>0){
            if(res.size()==0){
                for(int i = 0;i<mp[digits[0]].size();i++){
                    res.push_back(mp[digits[0]][i]);
                }
            }else{
                int size = res.size();
                for(int i = 0;i<size;i++){
                    for(int j = 0;j<mp[digits[0]].size();j++){
                        res.push_back(res[0]+mp[digits[0]][j]);
                    }
                    res.erase(res.begin());
                }
            }
            digits = digits.substr(1,digits.size()-1);
        }
        return res;
    }
};