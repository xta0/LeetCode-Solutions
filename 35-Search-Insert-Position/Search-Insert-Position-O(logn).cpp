#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums.back()){
            return (int)nums.size();
        }
        if(target < nums[0]){
            return 0;
        }
        //binary search
        int len = (int)nums.size();
        int l=0; int r = len-1;
        while(l <= r){
            int m = (l+r)/2;
            if(nums[m] < target){
                l = m+1;
                if(l<len){
                    if(nums[l] > target){
                        return l;
                    }
                }else{
                        return len;
                }
            }else if(nums[m] == target){
                return m;
            }else{
                r = m-1;
                if(r >= 0){
                    if(nums[r] < target){
                        return r+1;
                    }
                }else{
                    return 0;
                    
                }
            }
        }
        return 0;
    }
};

int main(){
    
    Solution s;
    vector<int> input{1,3,5,6};
    cout<<s.searchInsert(input,5)<<endl;
    cout<<s.searchInsert(input,2)<<endl;
    cout<<s.searchInsert(input,7)<<endl;
    cout<<s.searchInsert(input,0)<<endl;
    
    
    
    return 0;
}
