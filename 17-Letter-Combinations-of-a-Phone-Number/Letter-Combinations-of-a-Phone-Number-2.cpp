#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        unordered_map<char,vector<char>> phone{
            {'2',{'a','b','c'}},
            {'3',{'d','e','f'}},
            {'4',{'g','h','i'}},
            {'5',{'j','k','l'}},
            {'6',{'m','n','o'}},
            {'7',{'p','q','r','s'}},
            {'8',{'t','u','v'}},
            {'9',{'w','x','y','z'}}
        };
        function<vector<string>(char,vector<string>&)> f
        = [&](char n, vector<string>& vec){
            vector<string> ans;
            vector<char> nums = phone[n];
            for(string str:vec){
                for(auto c:nums){
                    ans.push_back(str+c);
                }
            }
            return ans;
        };

        vector<string> result = {""};
        for(auto c:digits){
            result = f(c,result);
        }
        return result;
    }
};

int main(){




    return 0;
}