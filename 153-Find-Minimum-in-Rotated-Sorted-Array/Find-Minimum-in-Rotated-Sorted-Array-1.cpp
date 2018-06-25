#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        //no pivot
        if(nums[nums.size()-1] > nums[0]){
            return nums[0];
        }
        //two end search
        int l = 0; int r = nums.size() - 1;
        while( l <= r){
            if(nums[l+1]<nums[l]){
                return nums[l+1];
            }
            if(nums[r-1] > nums[r]){
                return nums[r];
            }
            l++;r--;
        }
        return -1;
    }
};

int main(){




    return 0;
}