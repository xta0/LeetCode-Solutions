#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Sliding window
// O(n)
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
                sum = max(sum,prices[r] - prices[l]);
            }else{
                l = r;
            }
            r++;
        }   
        return sum;
    }
};

int main(){




    return 0;
}