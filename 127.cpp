#include<iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int res = 0,sig = 0;
        while(n>0){
            if(n%2==1){
                res+=pow(2,31-sig);
            }
            sig++;
            n/=2;
        }
        return res;
    }
};