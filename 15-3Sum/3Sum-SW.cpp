#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
//K-Sum问题：双指针+滑动窗口
//Slide-Windown
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); ++i){
            if(i==0 || nums[i] != nums[i-1]){
                int n = nums[i];
                int left = i+1;
                int right = (int)nums.size()-1;
                //two sum
                while(left < right){
                    int total = n+nums[left] + nums[right];
                    if(total == 0){
                        vector<int>vec{n,nums[left],nums[right]};
                        ret.push_back(vec);
                        //略过重复元素
                        do{++left;}while(nums[left] == nums[left-1] && left<right);
                        do{--right;}while(nums[right] == nums[right+1] && left<right);
                        
                    }else if(total > 0){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }
        return ret;
    }
};
int main(){
    
    Solution s;
//        vector<int> v = {-1, 0, 1, 2, -1, -4};
//        vector<int> v = {0,0,0,0};
//        vector<int> v = {3,0,-2,-1,1,2};
//        vector<int> v = {-2,0,1,1,2};
    vector<int> v = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    auto result = s.threeSum(v);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    
    return 0;
}
