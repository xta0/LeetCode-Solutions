#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return;
        }
        int w = 0;
        int r = 0;
        while(r < n ){
            if(nums[r] == 0){
              r++;
            }else{
              int v = nums[r];
              nums[w] = v;
              r++;
              w++;
            }   
        }
        while(w < n){
            nums[w] = 0;
            w++;
        }
    }
};

int main(){




    return 0;
}