#include <iostream>
#include <vector>
#include <string>
using namespace std;

//模板 #33
//O(log(n))
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        if(nums.size() == 1){
            return target == nums[0] ? 0:-1;
        }
        //二分查找
        //普通二分法比较nums[mid]和target之间的关系
        //对于rotated array，比较mid和nums[left]之间的关系来判断每一步搜索范围
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            //说明mid处于sorted array，这时，如果target < mid && target >= left，则进行正常二分查找
            if(nums[mid] >= nums[left]){
                if(target >= nums[left] && target < nums[mid]){
                    right = mid-1;
                }else{
                    left = mid + 1;
                }
            }
            //说明mid处于rotated array，这时，如果target > mid && target <= right，则进行正常二分查找
            else{
                if(target <= nums[right] && target > nums[mid]){
                    left = mid + 1;
                }else{
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};

int main(){




    return 0;
}