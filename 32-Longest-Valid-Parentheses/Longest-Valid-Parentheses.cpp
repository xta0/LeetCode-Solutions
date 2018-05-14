#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<char> stk;
        int total=0,curr = 0;
//        bool flag = false;
        for(int i=0; i<s.length(); ++i){
            char c = s[i];
            if(c == ')'){
                if(!stk.empty()){
                    if(stk.empty()){}
                    curr++;
                    stk.pop();
                }else{
                    curr = 0;
                }
            }else{
                stk.push(c);
            }
            if(curr > total){
                total = curr;
            }
        }
        
        return total*2;
    }
};

int main(){
    Solution s;
//    cout<<s.longestValidParentheses("(()")<<endl;
//    cout<<s.longestValidParentheses(")()())")<<endl;
//    cout<<s.longestValidParentheses("()(())")<<endl;
    cout<<s.longestValidParentheses("()(()")<<endl;
    
    
    
    return 0;
}
