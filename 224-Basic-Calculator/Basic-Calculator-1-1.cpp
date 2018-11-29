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
    vector<string> infix2postfix(string& s){
        vector<string> postfix;

    }
public:
    int calculate(string s) {
        
    }
};

int main(){




    return 0;
}