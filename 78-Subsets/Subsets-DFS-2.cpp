#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;



class Solution {
    void dfs(vector<int>& nums,int index, vector<int>& chosen, vector<vector<int>>& result){
        result.push_back(chosen);
        for(int i = index; i<nums.size(); i ++ ){
            chosen.push_back(nums[i]);
            dfs(nums,i+1, chosen,result);
            chosen.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {};
        vector<int> chosen;
        dfs(nums,0,chosen,result);
        return result;
        
    }
};


int main(){




    return 0;
}