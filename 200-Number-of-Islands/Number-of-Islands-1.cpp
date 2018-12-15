#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Solution: DFS
Time: O(N)
Space: O(N)
*/
class Solution {
public:
    void dfs(int i, int j, int w, int h, vector<vector<char>>& grid, vector<vector<bool>>& marks){
        if(grid[i][j] == '0'){
            return;
        }
        if(marks[i][j] == true){
            return ;
        }
        marks[i][j] = true;
        //dfs
        if(j+1 < w){
            dfs(i,j+1,w,h,grid,marks);
        }
        if(i+1 < h){
            dfs(i+1,j,w,h,grid,marks);
        }
        if(j-1 >= 0){
            dfs(i,j-1,w,h,grid,marks);
        }
        if(i-1>=0){
            dfs(i-1,j,w,h,grid,marks);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        if(!h) return 0;
        int w = grid[0].size();
        if(!w) return 0;
        vector<vector<bool>> marks = vector<vector<bool>>(h,vector<bool>(w,false));
        int count = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j] == '1' && marks[i][j] == false){
                    dfs(i,j,w,h,grid,marks);
                    count ++;
                }
            }
        }
        return count;
    }
};
int main(){
    
    return 0;
}
