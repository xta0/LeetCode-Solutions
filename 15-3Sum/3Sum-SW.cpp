#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
//sort + 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }else if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                }else{
                    //=0
                    ans.push_back({nums[i],nums[l],nums[r]});
                    //skip duplicated elements
                    while(nums[l] == nums[l+1] && l<r){
                        l++;
                    }
                    //skip duplicated elements
                    while(nums[r] == nums[r-1] && l<r){
                        r--;
                    }
                    l++;
                    r--;
                }
            }
            while(nums[i] == nums[i+1]){
                i++;
            }
        }

        return ans;
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
