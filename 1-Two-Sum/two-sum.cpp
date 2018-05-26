#include <iostream>
#include <map>
#include <vector>
using namespace std;

//hash-map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        map<int,int> dict;
 
        for(size_t i=0; i<nums.size(); ++i){
            int l = nums[i];
            int r = target -l;
            if(dict.find(r) != dict.end()){
                if(dict[r] != i){
                    result.push_back(i);
                    result.push_back(dict[r]);
                    break;
                }
            }
            dict[l] = i;
        }

        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,4};
    s.twoSum(nums, 6);
    
    return 0;
}
