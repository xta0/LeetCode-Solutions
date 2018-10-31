#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans{""};
        for(auto c : S){
            if(isalpha(c)){
                char upper = toupper(c);
                char lower = tolower(c);
                vector<string>tmp = ans;
                for(auto &x: ans){
                    x+=upper;
                }
                for(auto &x:tmp){
                    ans.push_back(x+=lower);
                }
            }else{
                for(auto &x:ans){
                    x+=c;
                }
            }
        }
        return ans;
    }
};




int main(){




    return 0;
}