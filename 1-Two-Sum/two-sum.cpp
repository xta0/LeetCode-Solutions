#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        for(size_t i=0; i<nums.size(); ++i){
            for(size_t j = i+1; j<nums.size(); ++j){
                if(nums[j] + nums[i] == target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};
