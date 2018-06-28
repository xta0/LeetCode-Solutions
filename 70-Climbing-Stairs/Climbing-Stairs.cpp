#include <iostream>
#include <vector>
using namespace std;

//DP
//a[n] = a[n-2]+2
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout<<s.climbStairs(3)<<endl;
    return 0;
}
