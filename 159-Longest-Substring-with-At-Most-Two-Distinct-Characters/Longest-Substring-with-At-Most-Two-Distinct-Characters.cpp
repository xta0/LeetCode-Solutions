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
使用滑动窗口模板
*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty()){
            return 0;
        }
        if(s.size() < 2){
            return 1;
        }
        
        unordered_map<char,int> um;
        int left = 0; int right =0; int len = 0;
        int counter =0;
        //sliding window
        while(right < s.size()){
            char c = s[right];
            um[c]++;
            if(um[c]==1){
                counter++;
            }
            while(counter > 2){
                //update the length
                len = max(len, right - left);
                char c = s[left];
                um[c]--;
                if(um[c]==0){
                    counter--;
                }
                left ++;   
            }
            right ++;
        }
        return max(len,right-left);
    }
};

int main(){




    return 0;
}