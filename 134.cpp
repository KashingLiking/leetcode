#include<iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        if(s1.size()==0){
            return (s2 == s3);
        }
        if(s2.size()==0){
            return (s1 == s3);
        }
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<bool>>map(len1+1,vector<bool>(len2+1,false));
        map[0][0] = true;
        for(int i = 1;i <= len1;i++){
            if(map[i-1][0]&&s1[i-1]==s3[i-1]){
                map[i][0] = true;
            }else{
                break;
            }        
        }
        for(int i = 1;i <= len2;i++){
            if(map[0][i-1]&&s2[i-1]==s3[i-1]){
                map[0][i] = true;
            }else{
                break;
            }        
        }
        for(int i = 1;i<=len1;i++){
            for(int j = 1;j<=len2;j++){
                if((map[i-1][j]&&s1[i-1]==s3[i+j-1]) || (map[i][j-1]&&s2[j-1]==s3[i+j-1])){
                    map[i][j] = true;
                }
            }
        }
        return map[len1][len2];
    }
};