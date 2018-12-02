#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//brute force
//O(n^2)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2){
            return false;
        }
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                if(j-i>=1){
                    if( k==0 ){
                        if(sum == 0){
                            return true;
                        }
                    }else{
                        if(sum % k == 0){
                            return true;
                        }
                    }
                }
                
            }
        }
        return false;
        
    }
};

int main(){
    Solution s;
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    cout<<s.checkSubarraySum(nums,k)<<endl;
    return 0;
}
