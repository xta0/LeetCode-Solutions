#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1){
            return {"()"};
        }else {
            vector<string> last = generateParenthesis(n-1);
            vector<string> ret;
            for(auto str : last){
                string tmp;
                for(int i=0;i<=str.length();++i){
                    tmp = str;
                    string s = tmp.insert(i, "()");
                    ret.push_back(s);
                }
            }
            std::sort(ret.begin(), ret.end());
            ret.erase(std::unique(ret.begin(), ret.end()), ret.end());
            return ret;
        }  
    }
};

int main(){
    Solution s;
    s.generateParenthesis(2);
    cout<<endl<<"----------";
    s.generateParenthesis(3);
    cout<<endl<<"----------";
    s.generateParenthesis(4);




    return 0;
}