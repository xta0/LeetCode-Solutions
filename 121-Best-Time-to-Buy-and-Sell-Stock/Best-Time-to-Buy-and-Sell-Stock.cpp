#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Brutoal force
// O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int b = 0;
        int s = 0;
        for(int i=1; i<prices.size();i++){
            if(prices[i] > prices[i-1]){
                b = prices[i-1];
                s = prices[i];
            }
        }
        return s-b;

        
    }
};

int main(){




    return 0;
}