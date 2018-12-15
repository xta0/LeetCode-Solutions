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

/*
Solution: Union Find
Time: O(N)
Space: O(N)
*/

/*
1. 对矩阵中所有1的元素进行初始化，父节点为本身
2. 遍历matrix所有节点，对1的节点进行相邻合并（检查两个方向，左和上）
3. 找到Matrix中有多少个独立的root
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        if(!h){
            return 0;
        }
        int w = grid[0].size();
        vector<int> parents(h*w,0);
        int count = 0;
        for(int i=0;i<h;i++){
            for(int j=0; j<w;j++){
                //2d index -> 1d index
                int index = w*i + j;
                if(grid[i][j] == '1'){
                    parents[index]=1;
                    count++;
                }
            }
        }
        //find 
        auto findRoot = [&](int i){
            while(i != parents[i]){
                i = parents[i];
            }
            return i;
        };
        //union
        auto unionTwo = [&](int i, int j){
            int root1 = findRoot(i);
            int root2 = findRoot(j);
            
        };


    }
};
int main(){




    return 0;
}