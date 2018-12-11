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
Solution: Iteration / Recurrsion
Time: O(N)
Space: O(1)
*/
class Solution {
    string calculate(string& exp, int index){
        if(exp[index-1] == 'T'){
            return string(1,exp[index+1]);
        }else{
            return string(1,exp[index+3]);
        }
    }
public:
    string parseTernary(string expression) {
        int i = expression.size()-1;
        while(i>=0){
            if(expression[i] == '?'){
                string r = calculate(expression,i);        
                expression.replace(i-1,5,r);
                i = expression.size();
            }
            i--;
        }
        return expression;
    }
};

int main(){




    return 0;
}