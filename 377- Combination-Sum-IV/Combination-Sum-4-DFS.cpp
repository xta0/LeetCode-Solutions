#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int index, int target, vector<int>&nums, vector<int>& chosen, int& result){
        //剪枝
        if(target == 0){
            result ++;
            // for(auto n:chosen){
            //     cout<<n<<" ";
            // }
            // cout<<endl;
            return;
        }
        //剪枝
        if(target < 0){
            return;
        }
        for(int i=0; i<nums.size(); ++i){
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            //观察解空间树，避免元素，令index=i
            dfs(0, target,nums,chosen,result);
            target += n;
            chosen.pop_back();
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int ret=0;
        vector<int> chosen;
        dfs(0,target, nums, chosen,ret);
        return ret;
    }
};
int main(){

    Solution s;
    vector<int> v = {1, 2, 3};
    auto result = s.combinationSum4(v,4);
    cout<<result<<endl;

    return 0;
}