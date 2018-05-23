#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//全排列-深搜
class Solution {
private:
    void dfs( vector<int>& nums, vector<int>& chosen, vector<vector<int>>& results){
        if(nums.size() == 0){
            results.push_back(chosen);
        }else{
            for(int i = 0; i<nums.size(); ++i){
                int n = nums[i];
                chosen.push_back(n);
                nums.erase(nums.begin()+i);
                dfs(nums,chosen,results);
                chosen.pop_back();
                nums.insert(nums.begin()+i,n);
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        dfs(nums,vec,ret);
        return ret;
    };
};

int main(){
    Solution s;
    vector<int> input({1,2,3});
    auto result = s.permute(input);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    return 0;
}
