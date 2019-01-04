#include <iostream>
#include <vector>

using namespace std;

/*
Solution: Greedy
Time: O(N)
Space: O(1)
*/
/*
1. 不断更新每个位置最远能跳到的位置，如果该位置reach到数组末尾 return  true
2. 如果i>maxReach，说明当前已经走到最远能reach的距离，此时return false
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <2){
            return true;
        }
        int maxReach = 0;
        for(int i=0;i<nums.size() && i<=maxReach;i++){
            maxReach = max(maxReach,nums[i]+i);
            if(maxReach >= nums.size()-1){
                return true;
            }
        }
        return false;
    }
};

int main(){




    return 0;
}