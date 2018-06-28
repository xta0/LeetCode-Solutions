#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

//遇到符号弹出两个操作数，计算后放入栈中
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s : tokens){
            if(!(s == "+" || s == "/" || s == "*" || s =="-")){
                stk.push(stoi(s));
            }else{
                //pop two elements
                int sr = stk.top();stk.pop();
                int sl = stk.top();stk.pop();
                
                int result = 0;
                if(s == "+"){
                    result = sl + sr;
                }else if( s=="-"){
                    result = sl-sr;
                    
                }else if(s == "*"){
                    result = sl* sr;
                }else{
                    result = sl / sr;
                }
                stk.push(result);
            }
        }
        return stk.top();
    }
};

int main(){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout<<s.evalRPN(tokens)<<endl;
    
    
    
    return 0;
}
