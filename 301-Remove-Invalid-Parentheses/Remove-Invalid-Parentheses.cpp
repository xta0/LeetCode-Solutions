#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
1. check wether a input string is valid
2. compute min number of unbalanced '(' and ')'
3. Try all possible way to remove 
*/
class Solution {
public:
    void check(string& s, int& cl, int& cr){
        for(auto c: s){
            if(c == '('){
                cl++;
            }else if(c==')'){
                if(cl > 0){
                    cl--;
                }else{
                    cr++;
                }
            }   
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int cl = 0;
        int cr = 0;
        check(s,cl,cr);


    }
};

int main(){




    return 0;
}