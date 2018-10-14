#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        std::sort(nums.begin(),nums.end());
        
        int sz = nums.size();
        int prod1 =0, prod2 = 0;
        prod1 = nums[0]*nums[1]*nums[sz-1];
        prod2 = nums[sz-1]*nums[sz-2]*nums[sz-3];
        return max(prod1,prod2);
                
    }
};

int main(){
    return 0;
}