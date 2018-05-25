#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

//DFS
//combination模板 参考#77
class Solution {
private:
    void dfs(int index, int target, vector<int>&nums, vector<int>& chosen, vector<vector<int>>& st){
        //剪枝
        if(target == 0){
            st.push_back(chosen);
            return;
        }
        //剪枝
        if(target < 0 || index >= nums.size()){
            return;
        }
        for(int i=index; i<nums.size(); ++i){
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            //观察解空间树，避免元素，令index=i
            dfs(i, target,nums,chosen,st);
            target += n;
            chosen.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> chosen;
        dfs(0,target, candidates, chosen,ret);
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> v = {2,3,5};
    auto result = s.combinationSum(v,8);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    return 0;
}
