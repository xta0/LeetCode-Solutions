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
        size_t h = triangle.size();
        vector<vector<int>> dp(triangle);
        for(int i=1;i<h;i++){
            for(int j=0;j<dp[i].size();j++){
                int lv = j-1>=0?dp[i-1][j-1]:INT_MAX;
                int rv = j<dp[i-1].size() ? dp[i-1][j]:INT_MAX;
                dp[i][j] += min(lv,rv);
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<dp[h-1].size();i++){
            if(dp[h-1][i]<ans){
                ans = dp[h-1][i];
            }
        }
        return ans;
        
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.minimumTotal(v)<<endl;
    
    
    
    return 0;
}
