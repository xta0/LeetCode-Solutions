#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int index = -1;
        int left=0, right = nums.size()-1;        
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else if(nums[mid] == target){
                index = target;
                break;
            }else{
                right = mid-1;
            }
        }
        if(index == -1){
            return {-1,-1};
        }
        //left search
        int lbound=index,rbound = index;
        for(int i=index-1; i>=0;i--){
            if(nums[i] == target){
                lbound --;
            }else{
                break;
            }
        }
        //right search
        for(int i=index+1; i<nums.size(); ++i){
            if(nums[i] == target){
                rbound++;
            }else{
                break;
            }
        }
        ret.push_back(lbound);
        ret.push_back(rbound);
        return ret;        
    }
};

int main(){
    Solution s;
    vector<int> input = {5,7,7,8,8,10};
    auto r = s.searchRange(input,8);
    for(auto n:r){
        cout<<n<<" ";
    }



    return 0;
}