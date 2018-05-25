#include <numeric>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//使用DFS对所有combination进行搜索
//1. DFS整体搜索框架参考 [#77. Combinations]
//2. 搜索前对数组进行预处理
//3. DFS进行剪枝处理
class Solution {
private:
    //index为每层数组循环的起始下标
    void dfs( int target, int index,vector<int>& nums, int rbounds, vector<int>& chosen, set<vector<int>>& sets){
        //剪枝1
        if(target == 0){
            sets.insert(chosen);
            return;
        }
        //剪枝2
        //1.target < 0
        //2.走到叶子节点
        if(target < 0 || index >= nums.size()){
            return ;
        }
        for(int i = index; i<=rbounds; ++i){
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            dfs(target,i+1, nums,rbounds,chosen,sets);
            target += n;
            chosen.pop_back();
        }
        
    }
    int rBound(vector<int>& v, int t){
        for(int i=0;i<v.size();i++){
            if(v[i] > t){
                return i-1;
            }else if(v[i] == t){
                return i;
            }
        }
        return (int)v.size()-1;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //预处理
        std::sort(candidates.begin(), candidates.end());
        int r = rBound(candidates, target);
        set<vector<int>> sets;
        vector<int> chosen;
        //搜索
        dfs(target, 0, candidates, r, chosen, sets);
        return {sets.begin(), sets.end()};
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