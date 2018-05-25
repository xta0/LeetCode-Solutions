#include <iostream>
#include <vector>

using namespace std;

//DFS，解题思路同 #40
class Solution {
private:
    void dfs(int k, int index, int target, vector<int>& nums, vector<int>& chosen, vector<vector<int>>& result){

        if(chosen.size() == k && target == 0){
             result.push_back(chosen);
            return;
        }
        for(int i = index;i<nums.size(); ++i){
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            dfs(k,i+1,target,nums,chosen,result);
            target += n;
            chosen.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> chosen;
        vector<vector<int>> ret;
        dfs(k,0,n,nums,chosen,ret);
        return ret;
    }
};

int main(){
    
    Solution s;
    auto result = s.combinationSum3(3,7);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    
    return 0;
}
