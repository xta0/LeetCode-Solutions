#include <iostream>
#include <vector>
using namespace std;

//Brutal Force solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int ret = INT_MIN;
        for(int i =0;i <nums.size(); ++i){
            int sum = nums[i];
               if(sum > ret){
                    ret = sum;
                }
            for(int j=i+1; j<nums.size(); ++j){
                sum += nums[j];
                if(sum > ret){
                    ret = sum;
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(v)<<endl;
    return 0;
}