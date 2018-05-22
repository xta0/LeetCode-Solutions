#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//全排列-深搜
class Solution {
private:
    void dfs( vector<int>& nums, int cl, vector<bool>& visited, vector<int>& vec, vector<vector<int>>& results){
        if(cl == nums.size()){
            results.push_back(vec);
            return;
        }
        
        for(int i = 0; i<nums.size(); ++i){
            if(visited[i] == true){
                continue;
            }
            int n = nums[i];
            vec.push_back(n);
            visited[i] = true;
            cl++;
            dfs(nums,cl, visited, vec,results);
            cl--;
            vec.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        vector<bool> used;
        dfs(nums,0,used,vec,ret);
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
