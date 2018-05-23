#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private: 
    void dfs(vector<int>& nums, vector<int>& chosen, set<vector<int>>& result){
        if(nums.size() == 0){
            return;
        }else{
            for(int i =0; i<nums.size(); ++i){
                int n = nums[i];
                chosen.push_back(n);
                result.insert(chosen);
                nums.erase(nums.begin()+i);
                dfs(nums,chosen,result);
                chosen.pop_back();
                nums.insert(nums.begin()+i, n);
            }
        }
    }
public:
    //subset- DFS
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> chosen;
        set<vector<int>> sets;
        dfs(nums,chosen,sets);
        sets.insert({});

        return {sets.begin(), sets.end()};
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