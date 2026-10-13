#include<iostream>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>res;
        unordered_map<string,unordered_map<string,double>>map;
        for(int i = 0;i<equations.size();i++){
            map[equations[i][0]][equations[i][1]] = values[i];
            map[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        for(int i = 0;i<queries.size();i++){
            if((!map.count(queries[i][0]))||(!map.count(queries[i][1]))){
                res.push_back(-1);
            }else if(queries[i][0] == queries[i][1]){
                res.push_back(1);
            }else{
                double re = 1;
                
            }
        }
    }
};