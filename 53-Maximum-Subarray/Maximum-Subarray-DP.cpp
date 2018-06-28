#include <iostream>
#include <vector>
#include <string>
using namespace std;

//DP
/*
dp[0] = nums[0]
dp[i] = max(nums[i], dp[i-1])
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int dpSum, maxSum;
        dpSum = maxSum= nums[0];
        for(int i=1; i<nums.size();i++){
            dpSum = max(nums[i],nums[i]+dpSum);
            maxSum = max(maxSum,dpSum);
        }
        return maxSum;
    }
};
int main(){




    return 0;
}