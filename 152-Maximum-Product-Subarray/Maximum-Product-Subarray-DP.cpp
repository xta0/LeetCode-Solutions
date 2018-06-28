#include <iostream>
#include <vector>
#include <string>
using namespace std;

//DP
//dp[n] = max(nums[n], dp[n]*dp[n-1])
class Solution
{
  public:
    int maxProduct(vector<int> &nums){
        if (nums.empty()){
            return 0;
        }
        int dpSum, maxSum;
        dpSum = maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++){
            dpSum = max(nums[i], nums[i] * dpSum);
            maxSum = max(maxSum, dpSum);
        }
        return maxSum;
    }
};
int main()
{

    return 0;
}