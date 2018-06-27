#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
DP: 递推方程为: dp[x][y] = dp[x-1][y] + dp[x][y-1]
---------
0   1   1
1   2   3
1   3   6
---------
从右下角的点向前递推，到达右下角（x,y）的路径数 = (x-1,y)的路径数 + (x,y-1)的路径数 
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0){
            return 0;
        }
        if( m == 1 || n == 1){
            return 1;
        }
        vector<vector<int>> dp(n,vector<int>(m,1));
        for(int x=1;x<n;x++){
            for(int y=1; y<m; y++){
                dp[x][y] = dp[x-1][y] + dp[x][y-1];
            }
        }
        return dp[n-1][m-1];
    }
};
int main(){
    Solution s;
    cout<<s.uniquePaths(3,2);
    return 0;
} 