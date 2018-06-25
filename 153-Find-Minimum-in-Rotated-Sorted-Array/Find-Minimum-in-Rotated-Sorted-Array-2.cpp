#include <iostream>
#include <vector>
#include <string>
using namespace std;

//二分查找
//模板同#33
//二分查找 return的条件不同
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        //binary search
        int left = 0; int right = (int)nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            //case 1: mid = left or mid = right
            if(mid == left || mid == right){
                return min(nums[left], nums[right]);
            }
            //case 2: mid is the pivot point
            if((nums[mid] < nums[mid-1]) && (nums[mid] < nums[mid+1])){
                return nums[mid];
            }
            //narrow down search range by comparing nums[mid] and nums[left]
            //then compare nums[left] and nums[right]
            if(nums[mid] >=  nums[left]){
                if(nums[left] > nums[right]){
                    left = mid + 1;
                }else{
                    right = mid-1;
                }
            }else{
                if(nums[left] > nums[right]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {3,1,2};
    Solution s;
    cout<<s.findMin(arr)<<endl;
    
    
    
    return 0;
}
