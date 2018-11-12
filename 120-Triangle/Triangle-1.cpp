#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

//dfs search
//超时
class Solution {
public:
    void dfs(vector<vector<int>>& arr, int i, int j, vector<int>& chosen, int& sum){
        if(i==arr.size()){
            for(auto x : chosen){
                cout<<x<<" ";
            }
            cout<<endl;
            sum = min(sum, accumulate(chosen.begin(),chosen.end(),0));
            return;
        }
        chosen.push_back(arr[i][j]);
        dfs(arr,i+1,j,chosen,sum);
        dfs(arr,i+1,j+1,chosen,sum);
        chosen.pop_back();
        
    } 
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum = INT_MAX;
        vector<int> vec = {};
        dfs(triangle,0,0,vec,sum);
        return sum;
    }
    
};

int main(){

    Solution s;
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.minimumTotal(v)<<endl;



    return 0;
}