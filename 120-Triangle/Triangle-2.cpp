#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//从底向上递推
//DP, f[i][j]表示从最顶上到(i,j)位置，和最小的值
//递推公式： f[i][j] = min(f[i-1][j-1],f[i-1][j]) + a[i][j]
//时间复杂度O(N^2), 空间复杂度O(N^2)
//注意：贪心法不对，从上到下和从下到上都不对
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        for(int i=dp.size()-2;i>=0;i--){
            for(int j=0;j<dp[i].size();j++){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.minimumTotal(v)<<endl;
    
    
    
    return 0;
}
