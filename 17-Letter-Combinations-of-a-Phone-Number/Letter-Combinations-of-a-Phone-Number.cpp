#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const map<char,vector<char>> dict = {
            {'1': {}},
            {'2': {'a','b','c'}},
            {'3': {'d','e','f'},},
            {'4': {'g','h','i'}},
            {'5': {'j','k','l'}},
            {'6': {'m','n','o'}},
            {'7': {'p','q','r','s'}},
            {'8': {'t','u','v'}},
            {'9': {'w','x','y','z'}},
        };
    
        vector<string> result;
        
        
        
        return result;
    }
};


int main(){
    
    return 0;
}
