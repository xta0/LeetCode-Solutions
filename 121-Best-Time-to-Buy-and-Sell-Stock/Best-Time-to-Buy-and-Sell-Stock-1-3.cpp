#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Solution: DP
// Time: O(n)
// Space: O(2*n)
/*
状态：
1. 第i天最大的受益dp[i]
2. 每天又有两种状态，持股：dp[i][1] ，空仓：dp[i][0]
状态转移方程：
1. 第i天空仓的最大受益为：max(继续空仓，卖出平仓) dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]) 
2. 第i天满仓的最大受益为：max(继续满仓，当天买入) dp[i][1] = max(dp[i-1][1], -prices[i])

找到ap[i][0]中最大的解，即为第i天平仓后的最大受益
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int res = 0;
        vector<vector<int>>dp(prices.size(),vector<int>(2,0));
        dp[0][0]  = 0; //当天没有股票
        dp[0][1]  = -prices[0];  //当天有一股股票
        for(int i=1;i<prices.size();i++){
            dp[i][1] = max(dp[i-1][1],-prices[i]); //只能买卖一次，因此dp[i][1]只能为负数
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
            res = max(res,dp[i][0]);
        }
        return res;

    }
};

int main(){




    return 0;
}