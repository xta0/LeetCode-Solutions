#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Slide-Windown
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); ++i){
            if(i==0 || nums[i] != nums[i-1]){
                int a = nums[i];
                //3 sum
                for(int j=i+1; j<nums.size(); ++j){
                    if(j == i+1 || nums[j] != nums[j-1] ){
                        int b = nums[j];
                        //two sum
                        int left = j+1;
                        int right = (int)nums.size()-1;
                        while(left < right){
                            int total = a+b+nums[left] + nums[right];
                            if(total == target){
                                vector<int>vec{a,b,nums[left],nums[right]};
                                ret.push_back(vec);
                                //略过重复元素
                                do{++left;}while(nums[left] == nums[left-1] && left<right);
                                do{--right;}while(nums[right] == nums[right+1] && left<right);
                                
                            }else if(total > target){
                                right--;
                            }else{
                                left++;
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};
int main(){
    
    Solution s;
    vector<int> v = {0,0,0,0};
    // vector<int> v = {1, 0, -1, 0, -2, 2};
    auto result = s.fourSum(v,1);
    for(auto vec: result){
        cout<<"[ ";
        for(auto n:vec){
            cout<<n<<" ";
        }
        cout<<"],"<<endl;
    }
    
    return 0;
    return 0;
}
