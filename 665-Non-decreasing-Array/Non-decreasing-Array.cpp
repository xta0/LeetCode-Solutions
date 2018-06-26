#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.empty()){
            return false;
        }
        int tmp  =nums[0];
        int i = 1;
        while(i<nums.size()){
            if(nums[i] > tmp){
                tmp = nums[i];
            }
        }
        for(int i =0; i<nums.size()-1; i++){

        }
        
    }
};

int main(){




    return 0;
}