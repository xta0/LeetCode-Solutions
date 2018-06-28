#include <iostream>
#include <vector>
using namespace std;

//Brutal Force solution
//Brutal Force solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int maxSum = nums[0];
        for(int i =0;i <nums.size(); ++i){
            int sum = 0;
            for(int j=i; j<nums.size(); ++j){
                sum += nums[j];
                maxSum = max(maxSum,sum);
            }
        }
        return maxSum;
    }
};

int main(){
    Solution s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(v)<<endl;
    return 0;
}