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

//思路:
//1. 将每个word翻转后存入字典
//2. 对每一个单词进行切分，如果左半部分是回文，右半部分在hash表，则构成一组解
//3. 如果右半部分是回文，左半部分在hash表，则也构成一组解
class Solution {
    bool isPalindrome(const string& s){
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> um;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            reverse(word.begin(),word.end());
            um[word] = i;
        }
        vector<vector<int>> ans;
        
        //处理""
        if(um.count("")){
            for(int i=0;i<words.size();i++){
                if(i != um[""] && isPalindrome(words[i])){
                    ans.push_back({um[""],i}); //{"",word}->{um[""],i}
                }
            }
        }
        
        for(int i=0; i<words.size();i++){
            string word = words[i];
            int sz = (int)word.size();
            for(int j=0;j<word.size();j++){
                //left part
                string ls = word.substr(0,j);
                //right part
                string rs = word.substr(j);
                //左边是回文，右边在hash表里，注意出现(1,1)的情况，注意判重
                if(isPalindrome(ls) && um.count(rs)  && um[rs]!=i){
                    ans.push_back({um[rs],i});
                }
                if(um.count(ls) && isPalindrome(rs) && um[ls]!=i){
                    ans.push_back({i,um[ls]}); //{“word”,""}->{i,um[""]};
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words = {"a",""};
    auto ret = s.palindromePairs(words);
    for(auto vec: ret){
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
