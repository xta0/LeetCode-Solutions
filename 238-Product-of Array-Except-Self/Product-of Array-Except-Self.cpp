#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
暴力法： O(n^2)
线性解法：构造两个数组
[1, a1, a1*a2, a1*a2*a3]
[a2*a3*a4, a3*a4, a4, 1]
结果数组为 然后两个数组一一对应相乘：[a2*a3*a4, a1*a3*a4, a1*a2*a4, a1*a2*a3]。
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        vector<int> ans(nums.size(),0);
        
        left[0] = 1;
        for(int i=1;i<left.size();i++){
            left[i] = left[i-1]*nums[i-1];
        }
        right[nums.size()-1] = 1;
        for(int i=right.size()-2;i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        }
        for(int i=0;i<ans.size();i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};

int main(){




    return 0;
}