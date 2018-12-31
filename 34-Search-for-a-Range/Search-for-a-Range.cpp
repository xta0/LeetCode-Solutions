#include <iostream>
#include <vector>

using namespace std;

/*
Solution: Binray Search
Time: O(logn)
Space: O(1)
*/
class Solution {
    int lowerBound(vector<int>& nums, int target){
        int lo = 0;
        int hi = nums.size()-1;
        while( lo <= hi ){
            int mid = lo + (hi-lo)/2;
            if( nums[mid] == target  ){
                if(mid == 0 || nums[mid-1] < target){
                    return mid;
                }else{
                    hi = mid-1;
                }
            }else if(nums[mid] > target){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return -1;
    }
    int upperBound(vector<int>& nums, int target, int lb){
        int lo = lb;
        int hi = nums.size()-1;
        while( lo <= hi ){
            int mid = lo + (hi-lo)/2;
            if( nums[mid] == target  ){
                if(mid == nums.size()-1 || nums[mid+1] > target){
                    return mid;
                }else{
                    lo = mid+1;
                }
            }else if(nums[mid] > target){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //先搜索下界
        int lb = lowerBound(nums,target);
        if(lb == -1){
            return {-1,-1};
        }
        //如果有下界，再搜索上界
        int ub = upperBound(nums,target,lb);
        return {lb,ub};
    }
};

int main(){
    Solution s;
    vector<int> input = {5,7,7,8,8,10};
    auto r = s.searchRange(input,8);
    for(auto n:r){
        cout<<n<<" ";
    }



    return 0;
}