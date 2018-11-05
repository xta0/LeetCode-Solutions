#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2 ){
            return nums.size();
        }
        int write = 2;
        for(int i= 2; i<nums.size();i++){
            if(nums[i] != nums[write-2]){
                nums[write++] = nums[i];
            }
        }
        return write;
    }
};

int main(){




    return 0;
}