#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 无特殊解法，观察+递推
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int index = sz-1;
        while( nums[index] < nums[index-1] ){
            index --;
            if(index == 0){
                break;
            }
        }
        if(index == 0){
            std::sort(nums.begin(), nums.end());
            return;
        }    
        //找到大于nums[index]最小的数
        //std::sort(nums.begin()+index, nums.end());
        //也可以不用sort
        int tmp = INT_MAX;
        int target_index = 0;
        for(int i = index+1; i<nums.size(); ++i){
            if(nums[i] > nums[index]){
                if(nums[i] < tmp){
                    target_index = i;
                    tmp = nums[i];
                }
            }
        }
        //swap
        swap(nums[index], nums[target_index]);
        std::sort(nums.begin()+index, nums.end());
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    s.nextPermutation(nums);
    for(auto n: nums){
        cout<<n<<",";
    }
    return 0;
}