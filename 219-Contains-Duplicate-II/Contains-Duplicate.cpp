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
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()){
            return false;
        }
        unordered_map<int, int> um;
        for(int i=0;i<nums.size();i++){
            if(um.count(nums[i]) > 0){
                if(abs(um[nums[i]] - i)  <= k ){
                    return true;
                }
            }
            um[nums[i]] = i;
        }
        
        return false;
    }
};

int main(){
    
    Solution s;
    vector<int> v = {1,2,3,1,2,3};
    s.containsNearbyDuplicate(v,2);
    
    
    
    return 0;
}
