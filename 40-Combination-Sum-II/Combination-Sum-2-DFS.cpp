#include <numeric>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//使用DFS对所有combination进行搜索
class Solution {
private:
    //index为每层数组循环的起始下标
    void dfs( int target, int index,vector<int>& nums, vector<int>& chosen, vector<vector<int>>& results){
        if( index >= nums.size() ){
            if( std::accumulate(chosen.begin(),chosen.end(),0) == target){
                    results.push_back(chosen);
            }
            return;
        }else{
            for(int i = index; i<nums.size(); ++i){
                int n = nums[i];
                chosen.push_back(n);
               
                //观察决策树，下一层数组的起始index = 上一层index+1
                dfs(target,i+1, nums,chosen,results);
                chosen.pop_back();
            }
            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> chosen;
        dfs(target, 0, candidates, chosen, ret);
        // return {sset.begin(), sset.end()};
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> v = {2,5,2,1,2};
    auto result = s.combinationSum2(v,5);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    return 0;
}