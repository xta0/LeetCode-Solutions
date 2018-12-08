#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 模板同 #62
 DP: 递推方程为: dp[x][y] = dp[x-1][y] + dp[x][y-1]
 ---------
 0  1  1
 1  x  1
 1  1  2
 ---------
 从右下角的点向前递推，到达右下角（x,y）的路径数 = (x-1,y)的路径数 + (x,y-1)的路径数
 */
/*
DP Solution
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        vector<vector<int>> dp(h,vector<int>(w,0));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    if(i==0 && j==0 ){
                        dp[i][j]=1;
                    }else if(i==0){
                        dp[i][j] = dp[i][j-1];
                    }else if(j==0){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
        return dp[h-1][w-1];
    }
};

int main(){
    
    vector<vector<int>> maze = {{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout<<s.uniquePathsWithObstacles(maze)<<endl;
    
    
    return 0;
}
