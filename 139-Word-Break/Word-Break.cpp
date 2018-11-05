#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;

//dfs搜索问题
class Solution {
public:
    bool dfs(string& s, unordered_set<string>& wordDict, unordered_set<string>& us){
        if(us.count(s)){
            return false;
        }
        if(wordDict.count(s) || s.size() == 0){
            return true;
        }
        for(int i=1;i<=s.size();i++){
            string str1 = s.substr(0,i);
            if(wordDict.count(str1)){
                string str2 = s.substr(i);
                if(dfs(str2,wordDict,us)){
                    return true;
                }else{
                    us.insert(str2);
                }   
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict = {wordDict.begin(),wordDict.end()};
        unordered_set<string> us;
        return dfs(s,dict,us);
    }
};

int main(){
    Solution s;
    vector<string> dict =  {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout<<s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict)<<endl;;
}
