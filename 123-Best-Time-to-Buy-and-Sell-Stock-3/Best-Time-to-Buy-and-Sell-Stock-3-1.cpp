#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

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
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]); //可买卖多次。因此dp[i][1] 可能为正数
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
            res = max(res,dp[i][0]);
        }
        return res;

    }
};

int main(){




    return 0;
}