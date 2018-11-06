#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int recDecoding(string& s, unordered_map<string,int>&memo){
        size_t sz = s.size();
        if(sz == 0){
            return 1;
        }
        if(sz == 1){
            if(s[0] == '0'){
                return 0;
            }
            return 1;
        }
        int left = 0; int right=0;
        if( s[0] != '0' ){
            string sl = s.substr(1,sz-1);
            if(memo.count(sl)){
                left = memo[sl];
            }else{
                int ln = recDecoding(sl,memo);
                memo[sl] = ln;
                left = ln;
            }
        }
        string prefix = s.substr(0,2);
        if(prefix[0] != '0' && (stoi(prefix) > 0 && stoi(prefix) <= 26)){
            string sr = s.substr(2,sz-2);
            if(memo.count(sr)){
                right = memo[sr];
            }else{
                int rn = recDecoding(sr,memo);
                memo[sr] = rn;
                right = rn;
            }
        }
        return left + right;
    }
    int numDecodings(string s) {
        if(s.size() == 0 ){
            return 0;
        }
        unordered_map<string,int> memo;
        return recDecoding(s,memo);
    }
};

int main(){
    Solution s;
    cout<<s.numDecodings("2262")<<endl;
    
    
    
    return 0;
}
