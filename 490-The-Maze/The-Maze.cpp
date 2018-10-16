#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    
public:
    //i是行，j是列
    void dfs(int i, int j, int x, int y, int w, int h, vector<vector<int>>& maze, vector<vector<bool>>& mark, bool& b){
        if(mark[i][j]){
            cout<<"backtrack: {"<<i<<","<<j<<"}"<<endl;
            return ;
        }
        mark[i][j] = true;
        
        cout<<"bot: {"<<i<<","<<j<<"}"<<endl;
        for(int ii = 0; ii<mark.size();ii++){
            vector<bool> v = mark[ii];
            for(auto xx:v){
                cout<<xx<<" ";
            }
            cout<<endl;
        }
        cout<<"---"<<endl;
        if(i==x && j==y){
            //上下或者左右都是通的则表明失败
            if( (i+1<h && i-1 >=0 && maze[i+1][j]==0 && maze[i-1][j] == 0) ||
               (j-1>=0 && j+1<w && maze[i][j-1] == 0 && maze[i][j+1] == 0)){
                b = false;
            }else{
                b = true;
            }
            return ;
        }

        
        //向左走
        if(j-1>=0 && maze[i][j-1] == 0){
            dfs(i,j-1,x,y,w,h,maze,mark,b);
        }
        //向下走
        if(i+1 < h && maze[i+1][j] == 0){
            dfs(i+1,j,x,y,w,h,maze,mark,b);
        }
        //向右走
        if(j+1< w && maze[i][j+1]==0){
            dfs(i,j+1,x,y,w,h,maze,mark,b);
        }
        //向上
        if(i-1>=0&&maze[i-1][j] == 0){
            dfs(i-1,j,x,y,w,h,maze,mark,b);
        }
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int w = (int)maze[0].size();
        int h = (int)maze.size();
        // vector<bool> xx(w,false);
        vector<vector<bool>> cache(h,vector<bool>(w,false));
        bool ret = false;
        dfs(start[0],start[1],destination[0],destination[1],w,h,maze,cache,ret);
        return ret;
    }
};

int main(){
    
    vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> ball = {3,2};
    Solution s;
    cout<<s.hasPath(maze,start,ball)<<endl;
    
    return 0;
}
