#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
DFS solution + Memoization
Time Complexity: O(2^n) 
Space Complexity: O(1)
*/
class Solution {

    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            return h1 ^ h2;  
        }
    };
    void dfs(vector<vector<int>>& obstacleGrid, int i, int j, int w, int h, int& result){
        if(i<0||i>=h || j<0||j>=w){
            return ;
        }
        if(obstacleGrid[i][j] == 1){
            return ;
        }
        if(i==h-1 && j==w-1){
            result ++;
            return;
        }
        dfs(obstacleGrid,i+1,j,w,h,result);
        dfs(obstacleGrid,i,j+1,w,h,result);
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        int result = 0;
        unordered_map<pair<int,int>,int> um;
        dfs(obstacleGrid,0,0,w,h,result);
        return result;
        
    }
};

int main(){




    return 0;
}