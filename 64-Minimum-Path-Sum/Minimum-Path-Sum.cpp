#include <iostream>
#include <vector>
#include <string>
using namespace std;


//DP
//dp[x][y] = grid[x][y] + min( dp[x-1][y], dp[x][y-1] )
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<int>> dp(grid);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( i==0 && j==0){
                    continue;
                }
                //上边界
                else if( i==0 && j!= 0){
                    dp[i][j] += dp[i][j-1];
                }
                //左边界
                else if(j==0&& i!=0){
                    dp[i][j] += dp[i-1][j];
                }
                //一般情况
                else{
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

int main(){
    
     vector<vector<int>> grid  = {{1,3,1},{1,5,1},{4,2,1}};

    // vector<vector<int>> grid  = {
    //     {1,4,8,6,2,2,1,7},
    //     {4,7,3,1,4,5,5,1},
    //     {8,8,2,1,1,8,0,1},
    //     {8,9,2,9,8,0,8,9},
    //     {5,7,5,7,1,8,5,5},
    //     {7,0,9,4,5,6,5,6},
    //     {4,9,9,7,9,1,9,0}};
    Solution s;
    cout<<s.minPathSum(grid)<<endl;
    return 0;
}
