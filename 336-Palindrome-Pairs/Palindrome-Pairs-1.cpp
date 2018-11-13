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

//brutal force 
//超时
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
        if(words.size() < 2){
            return {};
        }
        unordered_map<string,int> um;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            um[word] = i;
        }
        vector<vector<int>> ans;
        for(int i=0;i<words.size();i++){
            string lw = words[i];
            for(int j=i+1;j<words.size();j++){
                string rw = words[j];
                if(isPalindrome(lw+rw)){
                    ans.push_back({um[lw],um[rw]});
                }
                if(isPalindrome(rw+lw)){
                    ans.push_back({um[rw],um[lw]});
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    auto res = s.palindromePairs(words);
    for(auto vec:res){
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
