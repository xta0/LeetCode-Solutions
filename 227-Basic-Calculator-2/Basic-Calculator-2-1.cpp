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
    bool isOperator(string s){
        char c = s[0];
        return (c=='+' || c=='-' || c=='*' || c=='/');
    }
    int level(char c) {
        if(c == '*' || c=='/'){
            return 1;
        }else{
            return 0;
        }
    }
    vector<string> infix2postFix(string& s){
        vector<string> postfix;
        int num = 0;
        stack<char> stk;
        for(auto c:s){
            if(isspace(c)){
                continue;
            }
            if( isdigit(c) ){
                num = num*10 + c-'0';
            }else{
                postfix.push_back(to_string(num));
                num = 0;
                //if the precedence of the c is lower than or equal to stk.top()
                while(!stk.empty() && level(c) <= level(stk.top())){
                    postfix.push_back(string(1,stk.top()));
                    stk.pop();
                    
                }
                stk.push(c);
            }
        }
        //append the last number
        if(num >= 0){
            postfix.push_back(to_string(num));
        }
        while(!stk.empty()){
            postfix.push_back(string(1,stk.top()));
            stk.pop();
        }
        return postfix;
    }
public:
    int calculate(string s) {
        auto postFix = infix2postFix(s);
        //
        for(auto s:postFix){
            cout<<s;
        }
        cout<<endl;
        //
        stack<int> stk;
        //evaluate the "reverse polish notation"
        for(auto &s:postFix){
            if(isOperator(s)){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                //check sign
                if(s == "*"){
                    stk.push(x*y);
                }else if(s == "/"){
                    stk.push(y/x);
                }else if(s == "-"){
                    stk.push(y-x);
                }else{
                    stk.push(x+y);
                }
            }else{
                stk.push(stoi(s));
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
int main(){
    Solution s;

    s.calculate("3+2*2-6/3+1"); //  322*+63/-1+
    



    return 0;
}