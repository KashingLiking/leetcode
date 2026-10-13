#include<iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int sig = 0,aflag = a.size()-1,bflag = b.size()-1;
        while(aflag>=0&&bflag>=0){
            int num = a[aflag]+b[bflag]-'0'-'0'+ sig;
            sig = num/2;
            char next = num%2 + '0';
            res = next + res;
            aflag--;
            bflag--;
        }
        while(aflag>=0){
            int num = a[aflag] - '0' + sig;
            sig = num/2;
            char next = num%2 + '0';
            res = next + res;
            aflag--;
        }
        while(bflag>=0){
            int num = b[bflag] - '0' + sig;
            sig = num/2;
            char next = num%2 + '0';
            res = next + res;
            bflag--;
        }
        if(sig!=0){
            res = '1' + res;
        }
        return res;
    }
};