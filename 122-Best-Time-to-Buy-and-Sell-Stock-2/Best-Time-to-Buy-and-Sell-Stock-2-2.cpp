#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

/*
Solution: Greedy
Time: O(n)
Space: O(1)
*/
/*
因为每天可以买卖数次，因此可以指定贪心策略为：
1. 如果第二天价格比第一天高，就卖出
2. 如果第三天价格比第二天高，则第二天卖出后买进
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }      
        int buy = 0;
        int r = 1;
        int p = 0;
        while(r < prices.size()){
            //如果第二天价格比第一天高，则卖出，累加利润
            if(prices[r] > prices[r-1]){
                p += prices[r] - prices[buy];
            }
            //如果价格低，则买入
            buy = r;
            r++;
        }
        return p;
    }
};
int main(){





    return 0;
}