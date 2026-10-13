#include<iostream>
using namespace std;

#include<tuple>

using T = tuple<int,int,int>;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<T>qp;
        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                if(qp.size()<k){
                    T tmp = {nums1[i]+nums2[j],nums1[i],nums2[j]};
                    qp.push(tmp);
                }else{
                    int sum = nums1[i]+nums2[j];
                    if(sum<get<0>(qp.top())){
                        T tmp = {sum,nums1[i],nums2[j]};
                        qp.push(tmp);
                        qp.pop();
                    }else{
                        break;
                    }
                }
            }
        }
        vector<vector<int>>res;
        while(!qp.empty()){
            vector<int>tp;
            T tmp = qp.top();
            tp.push_back(get<1>(tmp));
            tp.push_back(get<2>(tmp));
            res.push_back(tp);
            qp.pop();
        }
        return res;
    }
};