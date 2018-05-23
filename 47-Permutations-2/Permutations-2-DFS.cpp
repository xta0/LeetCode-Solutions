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
            //每一层用一个数组记录已经遍历的数字
            vector<int> visited;
            for(int i = 0; i<nums.size(); ++i){
                int n = nums[i];
                if(find(visited.begin(),visited.end(),n) != visited.end()){
                    continue;
                }
                visited.push_back(n);
                chosen.push_back(n);
                nums.erase(nums.begin()+i);
                dfs(nums,chosen,results);
                chosen.pop_back();
                nums.insert(nums.begin()+i,n);  
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        dfs(nums,vec,ret);
        return ret;
    };
};

int main(){
    Solution s;
    vector<int> input({1,2,2,3});
    auto result = s.permuteUnique(input);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    return 0;
}
