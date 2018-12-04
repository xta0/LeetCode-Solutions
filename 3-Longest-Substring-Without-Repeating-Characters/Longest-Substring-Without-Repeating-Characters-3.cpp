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
//使用滑动窗口模板
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }
        unordered_map<char,int> um;
        int left = 0; int right = 0; int len = 0;
        int counter = 0;
        
        while(right < s.size()){
            char c = s[right];
            um[c]++;
            if(um[c] > 1){
                counter+=1;
                len = max(len, right-left);
            }
            
            while(counter > 0){
                um[s[left]] --;
                if(um[s[left]] == 1){
                    counter -=1;
                }
                left++;
            }
            right++;            
        }
        return max(len,right-left);
    }
};
/*
 {
    p:1
    w:2
 }
 pwwkew
 | |
 */
int main(){
    
    Solution s;
    auto r = s.lengthOfLongestSubstring("au");
    cout<<r<<endl;
    
    return 0;
}
