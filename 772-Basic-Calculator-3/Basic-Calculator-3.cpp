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
        return ( c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')');
    }
    int level (char c){
        if(c == '*' || c=='/'){
            return 1;
        }else if(c=='('){
            return -1;
        }
        return 0;
    }
    vector<string> infix2postfix(string& s){
        vector<string> postfix;
        string num = "";
        stack<char> stk;
        int i = 0;
        while(i<s.size()){
            char c = s[i];
            if(isspace(c)){
                i++;
                continue;
            }
            //multiple digits
            //12+1
            if( isdigit(c)){
                do{
                    num+=c;
                    i++;
                    c=s[i];
                }while(isdigit(c));
                postfix.push_back(num);
                num = "";
                continue;
            }else if( c=='('){
                stk.push(c);
            }else if(c == ')'){
                while(stk.top() != '('){
                    postfix.push_back(string(1,stk.top()));
                    stk.pop();
                }
                //pop '('
                stk.pop();
            }else{
                //+,-,*,/
                while(!stk.empty() && level(c) <= level(stk.top())){
                    postfix.push_back(string(1,stk.top()));
                    stk.pop();
                }
                stk.push(c);
            }
            
            ++i;
        }
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
        stack<long> stk;
        for(auto &s : postfix){
            if(isOperator(s)){
                long x = stk.top();
                stk.pop();
                long y = stk.top();
                stk.pop();
                if( s== "+"){
                    stk.push(x+y);
                }else if(s=="-"){
                    stk.push(y-x);
                }else if(s=="*"){
                    stk.push(x*y);
                }else{
                    stk.push(y/x);
                }
            }else{
                stk.push(stol(s));
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
    cout<<s.calculate("0-2147483648")<<endl;
    
    
    
    
    return 0;
}
