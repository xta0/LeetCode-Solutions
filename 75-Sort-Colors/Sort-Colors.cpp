#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()){
            return;
        }
        int l=0, r=nums.size()-1;
        int m = 0;
        
        while(l<=r){
            if(nums[l] > nums[r]){
                swap(nums[l],nums[r]);
            }
            l++;
            r--;
        }
    }
};


int main(){




    return 0;
}