#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
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
            if(prefixSum >= s){
                len = min(len, i+1);
            }
            int target = prefixSum-s;
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




    return 0;
}