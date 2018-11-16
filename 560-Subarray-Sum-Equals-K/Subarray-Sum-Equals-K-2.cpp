#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

//使用prefix sum array
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        int ans = 0;
        unordered_map<int,int> um;
        for(int i=0; i<nums.size();i++){
            int prefixSum = prefix[i];
            //
            if(prefixSum == k){
                ans+=1;
            }
            //find prifix sum that can satisfy the equation:
            //prifx[i] - prefix[x] = k
            //find prefix[x] which equals to prefix[i]-k;
            int target = prefixSum-k;
            if(um.count(target)){
                ans+=um[target];
            }
            um[prefixSum]++;
        }
        return ans;
    }
};
int main(){




    return 0;
}