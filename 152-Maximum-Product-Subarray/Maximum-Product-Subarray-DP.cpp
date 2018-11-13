#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] > 0){
                mx = max(nums[i],mx*nums[i]);
                mn = min(nums[i],mn*nums[i]);
            }else{
                //如果nums[i]是负数，
                //那么最大值是最小值*nums[i]或者nums[i]自己
                //最小值等于最大值*nums[i]或者num[i]自己
                int t = mx;
                mx = max(mn*nums[i],nums[i]);
                mn = min(t*nums[i],nums[i]);

            }
            ans = max(ans,mx);
        }
        return ans;
    }
};
int main()
{

    return 0;
}