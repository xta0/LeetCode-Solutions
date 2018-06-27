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
        if(i<0 && j<0){
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
        int x = grid.size()-1;
        int y = grid[0].size()-1;
        int sum = 0;
        helper(grid,x,y,sum);
        return sum;
    }
};

int main(){




    return 0;
}