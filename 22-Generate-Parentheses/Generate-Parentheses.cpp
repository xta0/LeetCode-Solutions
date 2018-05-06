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
            vector<string> ret (last);
            for(auto str : last){
                //left
                string l = "()" + str;
                ret.push_back(l);
                //right
                string r = str + "()";
                ret.push_back(r);
                //enclose
                string e = "("+str+")";
                ret.push_back(e);
            }
            //去重
            auto itor = std::unique(ret.begin(),ret.end());
            ret.erase(itor,ret.end());
            for(auto s:ret){
                cout<<s<<endl;
            }
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