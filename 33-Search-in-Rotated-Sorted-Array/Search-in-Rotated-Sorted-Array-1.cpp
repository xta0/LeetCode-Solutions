#include <iostream>
#include <vector>
#include <string>
using namespace std;

//O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        if(nums.size() == 1){
            return target == nums[0] ? 0:-1;
        }
        //no pivot
        if(nums[nums.size()-1] > nums[0]){
            auto itor = find(nums.begin(), nums.end(), target);
            if(itor != nums.end()){
                return (int)(itor-nums.begin());
            }else{
                return -1;
            }
        }
        //has pivot
        //1. find pivot index -- O(n)
        int index = (int)nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                return i;
            }
            if(nums[i+1] == target){
                return i+1;
            }
            if(nums[i+1] < nums[i]){
                index = i;
                break;
            }
        }
        
        //2. search the right half of the array -- O(log(n))
        auto itor = std::find(nums.begin()+index+1, nums.end(),target);
        if(itor != nums.end()){
            return (int)(itor - nums.begin());
        }else{
            return -1;
        }
    }
};

int main(){
    
    vector<int> v = {1,3};
    Solution s;
    s.search(v, 1);
    
    
    
    return 0;
}
