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

//brutal force
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            int count = 0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                count ++;
                if(sum == k){
                    ans = max(ans,count);
                }
            }
        }
        return ans;
        
    }
};
int main(){




    return 0;
}