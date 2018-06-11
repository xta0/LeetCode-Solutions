#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        for(int i=0;i<=nums.size()-k;++i){
            int max = INT_MIN;
            for(int j=i;j<k;j++){
                if(nums[j] > max){
                    max = nums[j];
                }
            }
            ret.push_back(max);
        }
        return ret;
    }
};

int main(){
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    Solution s;
    s.maxSlidingWindow(v,3);



    return 0;
}