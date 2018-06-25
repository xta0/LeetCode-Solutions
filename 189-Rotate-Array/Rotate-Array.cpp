#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 ){
            return;
        }
        int sz = (int)nums.size();
        k = k % sz;
        if(k == 0){
            return;
        }
        //将长度为k的tail，插入到nums前面即可
        vector<int> tail{nums.begin()+sz-k, nums.end()};
        nums.erase(nums.begin()+sz-k,nums.end());
        nums.insert(nums.begin(), tail.begin(),tail.end());
    }
};

int main(){
    vector<int> nums=  {1,2,3,4,5,6,7};
    Solution s;
    s.rotate(nums,2);
    for(auto x: nums){
        cout<<x<<" ";
    }

    return 0;
}
