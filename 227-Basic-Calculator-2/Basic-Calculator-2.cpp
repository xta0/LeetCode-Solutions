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
public:
    int calculate(string s) {
        char oper = ' ';
        int num = 0;
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(isdigit(c)){
                num = 10*num + c-'0';
            }else{
                if(c != ' '){
                    //c is an operator
                    if(c == '+'){
                       stk.push(num); 
                    }else if(c=='-'){
                        stk.push(-num);
                    }else{
                        int x = stk.top();
                        stk.pop();
                        if(c == '*'){
                            stk.push(x*num);
                        }else{
                            stk.push(x/num);
                        }
                    }
                    num = 0;
                    oper = ' ';
                }
            }
        }
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
    cout<<s.calculate("3+2*2")<<endl;



    return 0;
}