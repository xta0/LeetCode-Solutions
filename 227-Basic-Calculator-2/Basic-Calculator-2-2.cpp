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
keep tracking of last sign
1. if c is digit, update the num
2. if c is '+/-', push num to stack
*/
class Solution {
    void helper(stack<int>& stk, char sign, int num){
        if(sign == ' ' || sign == '+'){
            stk.push(num);
        }else if(sign == '-'){
            stk.push(-num);
        }else if(sign == '*'){
            int x = stk.top();
            stk.pop();
            stk.push(x*num);
        }else {
            int x = stk.top();
            stk.pop();
            stk.push(x/num);
        }
    }
public:
    int calculate(string s) {
        char sign = ' '; 
        int num = 0;
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if( isspace(c) ){
                continue;
            }
            if(isdigit(c)){
                num = 10*num + c-'0';
            }else{
                helper(stk,sign,num);
                num = 0;
                sign = c;
            }
        }
        //handle the last number
        helper(stk,sign,num);

        int result = 0;
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.calculate("5*10-4/2/1+1")<<endl;



    return 0;
}