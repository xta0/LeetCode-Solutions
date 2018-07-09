#include <iostream>
#include <vector>
#include <string>
using namespace std;

//divide & conqure
class Solution {
public:
    int helper(vector<int>& nums, int left, int right){
        if(left == right){
            return nums[left];
        }
        int center = (left + right)/2;
        int sumLeft = helper(nums,left,center);
        int sumRight = helper(nums,center+1,right);
        
        int index = center;
        int s1 = INT_MIN,s2=INT_MIN;
        while(left<=index){
            if(s1+nums[index] > s1){
                s1+=nums[index];
                index --;
            }else{
                break;
            }
        }
        index = center+1;
        while(index<=right){
            if(s2+nums[index] > s1){
                s2+=nums[index];
                index ++;
            }else{
                break;
            }
        }
        int sum = s1+s2;
        sum = max(sum,sumLeft);
        sum = max(sum,sumRight);
        return sum;
    }
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        return helper(nums,0,nums.size()-1);
    }
};
int main(){
    Solution s;
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(arr)<<endl;
    
    
    
    return 0;
}
