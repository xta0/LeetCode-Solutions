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

/*
 使用递归
 */
class Solution {
public:
    int helper(string& s, int start , int end, int k){
        if(start >= s.size() || end < 0){
            return 0;
        }
        
        unordered_map<char,int> um;
        for(int i=start;i<=end;i++){
            char c = s[i];
            um[c]++;
        }
        
        int idx = start;
        while(idx <= end && um[s[idx]] >= k){
            idx++;
        }
        if(idx>end){
            return end-start+1;
        }else{
            int left = helper(s, start, idx-1, k);
            int right = helper(s, idx+1, end, k);
            return max(left,right);
        }
    }
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size())   return 0;
        if(k == 0)  return (int)s.size();
        
        return helper(s, 0, (int)s.size()-1, k);
    }
};
int main(){
    
    Solution s;
    cout<<s.longestSubstring("bbaaacbd",3)<<endl;
    
    
    return 0;
}

int main(){

    Solution s;
    s.longestSubstring("aaabb",3);


    return 0;
}