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

class Solution {
private:
    struct PT{
        int x;
        int y;
    };
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int n = (int)obstacleGrid.size();
        int m = (int)obstacleGrid[0].size();
        int otop = 0; int oleft = 0; PT omid{0,0};
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int x=0;x<n; x++){
            for(int y=0;y<m;y++){
                if(obstacleGrid[x][y] == 1){
                    dp[x][y] = 0;
                    if( x==0 && y > 0) {
                        otop = y;
                    }else if(x > 0 && y == 0){
                        oleft = x;
                    }else{
                        omid = {x,y};
                    }
                }else{
                    if(x == 0){
                        if(otop > 0 && y > otop){
                            dp[x][y] = 0;
                        }else{
                            dp[x][y] = 1;
                        }
                    }
                    else if(y == 0){
                        if(oleft > 0 && x > oleft){
                            dp[x][y] = 0;
                        }else{
                            dp[x][y] = 1;
                        }
                    }else{
                        if(omid.x > 0 && omid.y > 0 && x==omid.x && y == omid.y){
                            dp[x][y] = 0;
                        }else{
                            dp[x][y] = dp[x-1][y] + dp[x][y-1];
                        }
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};

int main(){
    
    vector<vector<int>> maze = {{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout<<s.uniquePathsWithObstacles(maze)<<endl;
    
    
    return 0;
}
