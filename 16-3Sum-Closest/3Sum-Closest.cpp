#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>


using namespace std;
//Slide-Windown
//注意：
//1. sum可以等于target，
//2. 问题变成3sum，sum逼近target的过程中记录abs值即可
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int total= 0;
        int diff = INT_MAX;
        int ret = 0;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); ++i){
            if(i==0 || nums[i] != nums[i-1]){
                int n = nums[i];
                int left = i+1;
                int right = (int)nums.size()-1;
                while(left < right){
                    total = n+nums[left] + nums[right];
                    if(total == target){
                        return total;
                    }else if(total > target){
                        right--;
                    }else{
                        left++;
                    }
                    //
                    if(abs(total - target) < diff){
                        diff = abs(total - target);
                        ret = total;
                    }
                }
            }
        }
        return ret;
    }
};
int main(){
    
    Solution s;
    vector<int> v = {0,2,1,-3};
    auto result = s.threeSumClosest(v,1);
    cout<<result<<endl;
    
    return 0;
}
