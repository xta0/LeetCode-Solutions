#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 滑动窗口变种，解法同#121
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int l = 0, r=1;
        int sum = 0;
        while(r < prices.size()){
            if(prices[r] > prices[l]){
                if(r+1 < prices.size() && prices[r+1] < prices[r]){
                    sum += prices[r] - prices[l];
                    l = r;
                }
            }else{
                l = r;
            }
            r++;
        }
        sum += prices[r-1] - prices[l];
        return sum;
    }
};

int main(){
    vector<int> input = {6,1,3,2,4,1};
    Solution s;
    cout<<s.maxProfit(input)<<endl;
    
    
    
    return 0;
}
