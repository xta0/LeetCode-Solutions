#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& chosen, vector<vector<int>>& result){
        if(nums.size() == 0){
            return;
        }else{
            int n = nums.back();
            nums.pop_back();
            chosen.push_back(n);
            result.push_back(chosen);
            dfs(nums,chosen, result);
            chosen.pop_back();
            dfs(nums,chosen,result);
            nums.push_back(n);
        }
    }
public:
    //subset- DFS
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> chosen;
        vector<vector<int>> vec;
        dfs(nums,chosen,vec);
        vec.push_back({});
        return vec;
    }
};
int main(){
    
    Solution s;
    vector<int> input = {1,2,3};
    vector<vector<int>>ret = s.subsets(input);
    for(auto vec: ret){
        cout<<"[";
        for(auto n : vec){
            cout<<n<<",";
        }
        cout<<"],"<<endl;
    }
    return 0;
}
