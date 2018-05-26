#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

//DFS 搜索解空间
class Solution {
private:
    void dfs(int target, int index, vector<int>& nums, vector<int>& chosen, set<vector<int>>& result){
        if(target == 0 && chosen.size() == 3){
            // if(std::accumulate(chosen.begin(), chosen.end(),0) == 0)
            result.insert(chosen);
            return;
        }
        if(target < 0 || index >= nums.size()){
            return;
        }
        for(int i = index; i<=nums.size(); ++i){
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            dfs(target,index,nums,chosen,result);
            target += n;
            chosen.pop_back();
        }
    }
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> result;
        vector<int> chosen;
        sort(nums.begin(), nums.end());
        dfs(0,0,nums,chosen,result);
        return {result.begin(), result.end()};
    }
};

int main(){

    Solution s;
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    auto result = s.threeSum(v);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }

    return 0;


    return 0;
}