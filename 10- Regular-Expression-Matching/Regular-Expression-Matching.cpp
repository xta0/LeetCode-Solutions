#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() && p.empty()){
            return true;
        }
        if(s.empty() || p.empty()){
            return false;
        }
        //x*
        if(p.size() > 1 && p[1] == '*' ){
            string remaining_pattern = 
        }
        if(p[0] == '.' ){
            return isMatch(s.substr(1),p.substr(1));
        }
        if(p[0] != '.' && p[0] != '*'){
            if(s[0] != p[0]){
                return false;
            }else{
                return isMatch(s.substr(1),p.substr(1));
            }
        }
    }
};

int main(){




    return 0;
}