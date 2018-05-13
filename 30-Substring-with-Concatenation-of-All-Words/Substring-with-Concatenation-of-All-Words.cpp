#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0){
            return {};
        }
        vector<int> ret;
        int len = words[0].length();
        int count = words.size();
        map<string, int>mc; 
        map<string, int>mi;
        for(auto word: words){
            mc[word] = 0;
        }
        // bool scan = false;
        int c = 0;
        for(int r=0, l =0; r<s.length(); r+=len){
            string str = s.substr(r,len);
            if(mc.find(str) != mc.end()){
                if(mc[str] > 0){
                    /*
                    * If we hit the mc cache, there are 3 possibilites:
                    * words:[foo,bar]
                    * (1) barbar
                    *        |
                    * (2) barfoobar
                    *           |
                    * (3) barfoothebar
                    *              |
                    */
                    //滑动窗口左边界向右移动，这种case退化为寻找最长不重复字串
                    l = max(l, mi[str]+len);
                    if(c < count){
                        c = 1;
                    }else if(c == count){
                        c = 0;
                        ret.push_back(r);
                    }
                    //更新目标词的位置
                    mi[str] = r;
                }else{
                    c++;
                }
            }else{
                if(c>0){
                    c = 0;
                }
            }
        }
        return ret;        
    }
};

int main(){




    return 0;
}