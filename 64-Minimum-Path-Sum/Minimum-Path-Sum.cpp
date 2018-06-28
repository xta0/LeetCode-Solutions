#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 Input:
 [
 [1,3,1],
 [1,5,1],
 [4,2,1]
 ]
 Output: 7
 Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */
//DP
class Solution {
    
private:
    void helper(vector<vector<int>>& grid, int i, int j, int& sum){
        if(i==0 && j==0){
            sum += grid[i][j];
            return ;
        }
        sum += grid[i][j];
        int next_i = i; int next_j = j;
        if(j <= 0){
            next_i = i-1;
        }else if(i<=0){
            next_j = j-1;
        }else{
            if(grid[i-1][j] <= grid[i][j-1]){
                next_i = i-1;
            }else{
                next_j = j-1;
            }
        }
        helper(grid,next_i,next_j,sum);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x = (int)grid.size()-1;
        int y = (int)grid[0].size()-1;
        int sum = 0;
        helper(grid,x,y,sum);
        return sum;
    }
};

int main(){
    
    vector<vector<int>> grid  = {
        {1,4,8,6,2,2,1,7},
        {4,7,3,1,4,5,5,1},
        {8,8,2,1,1,8,0,1},
        {8,9,2,9,8,0,8,9},
        {5,7,5,7,1,8,5,5},
        {7,0,9,4,5,6,5,6},
        {4,9,9,7,9,1,9,0}};
    Solution s;
    cout<<s.minPathSum(grid)<<endl;
    return 0;
}
