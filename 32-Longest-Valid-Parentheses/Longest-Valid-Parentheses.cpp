#include <iostream>
#include <string>
#include <stack>
using namespace std;

//扫描一次
//使用stack保存index而不是‘(’
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() < 2){
            return 0;
        }
        int ret = 0;
        int left = -1;
        stack<int> stk;
        for(int i = 0; i <s.length(); i++){
            if(s[i] == '('){
                stk.push(i);
            }else{
                if(stk.empty()){
                    left = i;
                }else{
                    stk.pop();
                    if(stk.empty()){
                        ret = max(ret, i-left);
                    }else{
                        /*
                        0 1 2
                        ( ( )
                        当匹配到2时，pop出来1，此时长度取得是stack top的index，注意，不是1的index
                        */
                        int top = stk.top(); //这里很关键
                        ret = max(ret, i-top);
                    }
                }
            }
        }
        
        return ret;
    }
};

int main(){
    Solution s;
    cout<<s.longestValidParentheses(")()())")<<endl;
    cout<<s.longestValidParentheses(")()())")<<endl;
    cout<<s.longestValidParentheses("()(())")<<endl;
    cout<<s.longestValidParentheses("()(()")<<endl;
    cout<<s.longestValidParentheses("(()())())")<<endl;
    
    
    return 0;
}
