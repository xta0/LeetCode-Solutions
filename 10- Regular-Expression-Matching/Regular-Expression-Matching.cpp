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
        return match(s,p,0,0);
    }
    bool match(const string& s, const string& p, int i, int j){
        if(i==s.size()-1 && j==p.size()-1){
            return true;
        }else if()

    }
};

int main(){




    return 0;
}