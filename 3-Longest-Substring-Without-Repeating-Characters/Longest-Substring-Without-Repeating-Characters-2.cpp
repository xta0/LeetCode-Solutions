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
双指针+set
abcxa
1. 遍历每个字符，查看set中是否存在， 如果不存在放入set中
2. 如果存在，移动左边界直到重复的字符，左边界走过的字符如果在set中需要将其删除
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }
        unordered_set<char> us;
        int left = 0; int right = 0; int len = 0;
        while(right < s.size()){
            char c = s[right];
            if(!us.count(c)){
                us.insert(c);
            }else{
                len = max(len,right-left);
                while(s[left] != c){
                    us.erase(s[left]);
                    left++;
                }
                left++;
            }
            right ++;
        }
        return max(len,right-left);;
    }
};
int main(){
    
    Solution s;
    auto r = s.lengthOfLongestSubstring("au");
    cout<<r<<endl;
    
    
    
    return 0;
}
