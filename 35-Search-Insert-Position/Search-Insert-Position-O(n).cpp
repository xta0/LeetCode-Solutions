#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums.back()){
            return (int)nums.size();
        }
        if(target < nums[0]){
            return 0;
        }
        int ret = -1;
        for(int i=0;i<nums.size();++i){
            if(nums[i] >= target){
                ret = i;
                break;
            }
        }
        return ret;
    }
};

int main(){
    
    Solution s;
    vector<int> input{1,3,5,6};
    cout<<s.searchInsert(input,5)<<endl;
    cout<<s.searchInsert(input,2)<<endl;
    cout<<s.searchInsert(input,7)<<endl;
    cout<<s.searchInsert(input,0)<<endl;
    
    
    return 0;
}
