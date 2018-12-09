#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Solution: Brute force
// Time: O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1; j<prices.size();j++){
                if(prices[j] > prices[i]){
                    sum = max(sum, prices[j]-prices[i]);
                }
            }
        }
        return sum;
    }
};

int main(){




    return 0;
}