#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

/*
Solution: DFS 超时
Time Complexity: O(2^n)
Space Complexity: O(1)
*/

class Solution {
    void dfs(vector<vector<int>>& triangle, int i, int j, int sum, int& minSum){
        if(i<0 || i>=triangle.size() || j<0 || j>=triangle[i].size()){
            return;
        }
        // cout<<triangle[i][j]<<endl;
        sum += triangle[i][j];
        if(i == triangle.size()-1 ){ 
            minSum = min(sum, minSum);
            // cout<<"sum: "<<sum<<" ,minSum: "<<minSum<<endl;
            return ;
        }
        dfs(triangle,i+1,j,sum,minSum);
        dfs(triangle,i+1,j+1,sum,minSum);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
        dfs(triangle,0,0,0,minSum);
        return minSum;
    }
};
int main(){

    Solution s;
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.minimumTotal(v)<<endl;



    return 0;
}