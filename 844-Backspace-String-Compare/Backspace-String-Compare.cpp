#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
    string removeBackspace(const string& s){
        stack<char> stk;
        for(auto c:s){
            if(c !='#'){
                stk.push(c);
            }else{
                if(!stk.empty()){
                    stk.pop();
                }
            }
        }
        string str = "";
        while(!stk.empty()){
            char c = stk.top();
            stk.pop();
            str = string(1,c)+str;
        }
        return str;
    }
public:
    bool backspaceCompare(string S, string T) {
        string s1 = removeBackspace(S);
        string s2 = removeBackspace(T);
        return s1==s2;
    }
};

int main(){
    return 0;
}