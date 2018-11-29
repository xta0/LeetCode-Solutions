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
    bool isOperator(char c){
        return (c=='+' || c=='-' || c=='*' || c=='/');
    }
    int level(char c) {
        if(c == '*' || c=='/'){
            return 1;
        }else{
            return 0;
        }
    }
    //infix: "3+2*2-6/3+1"
    //postfix: "322*+63/-1+""
    /*
    Rules:
    char c 
    1. if c is number , output c
    2. if c is a space, skip
    3. if c is a sign, push to the stack
    4. if c is a sign whose level is greater than or equal to the top of the stack, pop the signs
    5. pop signs in the stack
    */
    string infix2postFix(string& s){
        string postfix = "";
        int num = 0;
        stack<char> stk;
        for(auto c:s){
            if(isspace(c)){
                continue;
            }
            if( isdigit(c) ){
                num = num*10 + c-'0';
            }else{       
                postfix += to_string(num);
                if(!stk.empty()){
                    while( level(stk.top()) >= level(c) ){
                        postfix+=stk.top();
                        stk.pop();
                    }
                }
                stk.push(c);
            }
        }
        while(!stk.empty()){
            postfix += stk.top();
            stk.pop();
        }
        return postfix;
    }
public:
    int calculate(string s) {
        string postFix = infix2postFix(s);
        stack<int> stk;
        cout<<postFix<<endl;
        return -1;
    }

};
int main(){
    Solution s;
    // s.calculate("  3 +2 * 2"); // 322*+
    s.calculate("3+2*2-6/3+1"); // 322*+
    



    return 0;
}