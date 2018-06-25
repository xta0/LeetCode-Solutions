#include <iostream>
#include <vector>
#include <string>
using namespace std;

//二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
            
        //at least 3 elements
        //binary search
        int left = 0; int right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(mid == right || mid == left){
                return min(nums[left], nums[right]);
            }
            if(nums[mid] <  nums[left] ){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;

    }
};

int main(){




    return 0;
}