#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
Solution: DP
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    /*
    由于有负数，使用两个数组，维护两个状态，最大值和最小值
    dpmax: 下标为i的max product subarry，包含i
    递推公式为：
        dpmax[i] = 
            if n[i] >= 0 then 
                max(n[i],n[i]*dpmax[i-1]) 
            else 
                max(n[i],dpmin[i-1]*n[i])
                
    dpmin: 下标为i的min product subarry，包含i
    递推公式为：
        dpmin[i] = 
            if n[i] >= 0 then
                min(n[i],dpmin[i-1]*n[i])
            else
                min(n[i],dpmax[i-1]*n[i])
    */
    int maxProduct(vector<int>& nums) {
        vector<int> dpmax(nums.size(),0);
        vector<int> dpmin(nums.size(),0);
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] >= 0){
                dpmax[i] = max(dpmax[i-1]*nums[i],nums[i]);
                dpmin[i] = min(dpmin[i-1]*nums[i],nums[i]);
            }else{
                dpmax[i] = max(dpmin[i-1]*nums[i],nums[i]);
                dpmin[i] = min(dpmax[i-1]*nums[i],nums[i]);
            }
        }
        int res = INT_MIN;
        for(auto m:dpmax){
            res = max(res,m);
        }
        return res;
        
    }
};
int main()
{

    return 0;
}