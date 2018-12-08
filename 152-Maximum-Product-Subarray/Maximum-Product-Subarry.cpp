#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Solution: Brute Force
Time Complexity: O(N^2)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxv = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int p = 1;
            for(int j=i;j<nums.size();j++){
                p *= nums[j];
                maxv = max(p,maxv);
            }
        }
        return maxv;
    }
};

int main(){




    return 0;
}