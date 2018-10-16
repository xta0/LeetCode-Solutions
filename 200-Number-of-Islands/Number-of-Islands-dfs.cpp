#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void dfs(int i,int j, int w, int h,  vector<vector<int>>& grids, vector<vector<bool>>& marks,int& count){
        if(marks[i][j] == true){
            return;
        }
        marks[i][j] = true;
        count ++;
        
        //right,east
        if(j+1 < w && grids[i][j+1] == 1){
            dfs(i,j+1,w,h,grids,marks,count);
        }
        //bottom
        if(i+1<h && grids[i+1][j]== 1){
            dfs(i+1,j,w,h,grids,marks,count);
        }
        //left
        if(j-1 >= 0 && grids[i][j-1]== 1){
            dfs(i,j-1,w,h,grids,marks,count);
        }
        //up
        if(i-1>=0 && grids[i-1][j] == 1){
            dfs(i-1,j,w,h,grids,marks,count);
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = (int)grid.size();
        if(!h) return 0;
        int w = (int)grid[0].size();
        if(!w) return 0;
        int count = 0;
        vector<vector<bool>> marks(h,vector<bool>(w,false));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j] == 1 && marks[i][j] == false){
                    int n = 0;
                    dfs(i,j,w,h,grid,marks,n);
                    count = max(count,n);
                }
            }
        }
        return count;
    }
};

int main(){
    
    vector<vector<int>> grids = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    Solution s;
    cout<<s.maxAreaOfIsland(grids)<<endl;;
    
    
    return 0;
}
