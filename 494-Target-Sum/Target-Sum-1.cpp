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

/*
DFS Solution
Time Complexity: O(2^n)
*/
class Solution {
    void dfs(vector<int>& nums, int index, int sum, int target, int& count){
        
       cout<<"index, "<<index<<", sum: "<<sum<<endl;
        if(index == nums.size()-1){
            if(sum == target){
               cout<<"found"<<endl;
                count+=1;
            }
            return;
        }
     
        dfs(nums,index+1,sum+nums[index+1], target,count);
        dfs(nums,index+1,sum-nums[index+1], target, count);

    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0){
            return 0;
        }
        int count = 0;
        dfs(nums,0,nums[0],S,count);
        dfs(nums,0,-nums[0],S,count);
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    cout<<s.findTargetSumWays(nums, 3)<<endl;
    
    
    
    return 0;
}
