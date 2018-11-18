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

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        vector<int> prefix;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        int len = 0;
        unordered_map<int,int> um;
        for(int i=0; i<nums.size();i++){
            int prefixSum = prefix[i];
            if(prefixSum == k){
                len = max(len, i+1);
            }
            int target = prefixSum-k;
            if(um.count(target)){
                int index = um[target];
                len = max(len, i-index);
            }else{
                if(!um.count(prefixSum)){
                    um[prefixSum] = i;
                }
                
            }
        }
        return len;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,0,-1};
    cout<<s.maxSubArrayLen(nums,-1)<<endl;;
    
    
    
    return 0;
}
