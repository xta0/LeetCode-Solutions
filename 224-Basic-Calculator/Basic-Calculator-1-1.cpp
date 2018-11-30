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

/*
//using reverse polish notation
1. if c is digit , update the num
2. if c is operator:
   - output the num
   - if c level(c) <= stack.top() then pop stack, output the signs, push c to the stack
   - else push c to the stack
   - reset num = 0
3. if c is a "(" then push to the stack
4. if c is a ")" then push num to stack, then pop stack until stack.top == '('
5. check if s[size.-1] == ')', else output num
*/
class Solution {
    bool isOperator(string s){
        char c = s[0];
        return ( c=='+' || c=='-' || c=='*' || c=='/');
    }
    int level (char c){
        if(c == '*' || c=='/'){
            return 1;
        }else{
            return 0;
        }
    }
    vector<string> infix2postfix(string& s){
        vector<string> postfix;
        int num = 0;
        stack<char> stk;
        for(auto &c:s){
            if(isspace(c)){
                continue;
            }else{
                if(isdigit(c)){
                    num = 10* num + c-'0';
                }else{
                    if( c=='('){
                        stk.push(c);
                    }else if(c == ')'){
                        postfix.push_back(to_string(num));
                        while(stk.top() != '('){
                            postfix.push_back(string(1,stk.top()));
                            stk.pop();
                        }
                        //pop '('
                        stk.pop();
                    }else{
                        //+,-,*,/
                        //precedence
                        postfix.push_back(to_string(num));
                        while(!stk.empty() && level(c) <= stk.top()){
                            postfix.push_back(string(1,stk.top()));
                            stk.pop();
                        }
                        stk.push(c);
                    }
                }
            }
        }
        //append the num
        postfix.push_back(to_string(num));

        //collect the result
        while(!stk.empty()){
            postfix.push_back(string(1,stk.top()));
            stk.pop();
        }
        return postfix;
    }
public:
    int calculate(string s) {
        auto postfix = infix2postfix(s);
        stack<int> stk;
        for(auto &s : postfix){
            if(isOperator(s)){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                if( s== "+"){
                     stk.push(x+y);
                }else{
                    stk.push(y-x);
                }
            }else{
                stk.push(stoi(s));
            }
        }
        int res = 0;
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.calculate("(1+2)-(4+3)")<<endl;




    return 0;
}