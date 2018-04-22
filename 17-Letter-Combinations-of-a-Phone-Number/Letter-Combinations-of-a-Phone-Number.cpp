#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    unordered_map<char,vector<char>> phone;
    vector<string> combination(const vector<string>& arr1, const vector<char>& arr2){
        vector<string> ret;
        if(arr1.size() == 0){
            for(auto x:arr2){
                ret.push_back(string(1,x));
            }
        }else{
            for(auto x: arr2){
                for(auto y: arr1){
                    string str = y + string(1,x);
                    ret.push_back(str);
                }
            }
        }
 
        return ret;
    }
    //((([],a),b),c...)
    vector<string> recursive(vector<string>arr1, const string& digits, int index){
        if(index >= digits.length()){
            return arr1;
        }else{
            char c = digits[index];
            vector<char> arr2 = phone[c];
            vector<string> tmp = combination(arr1, arr2);
            return recursive(tmp, digits,++index);
            
        }
    }
public:
    vector<string> letterCombinations(string str) {
        phone = {
            {'1', {}},
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'},},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}},
        };
        return recursive({},str,0);
    }
};


int main(){
    return 0;
}
