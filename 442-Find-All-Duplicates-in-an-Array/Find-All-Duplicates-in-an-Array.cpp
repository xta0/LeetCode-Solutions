#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//核心思路是如何对已经遍历的元素做上标记
//解法很难想出来，参考https://www.youtube.com/watch?v=GeHOlt_QYz8&t=700s
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> us;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            if(nums[index] < 0){
                us.insert(abs(nums[i]));
            }else{
                nums[index] = -nums[index];
            }
        }
        return {us.begin(), us.end()};
    }
};

int main(){




    return 0;
}