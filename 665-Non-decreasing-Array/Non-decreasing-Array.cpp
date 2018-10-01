#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.empty()){
            return false;
        }
        if(nums.size() == 1){
            return true;
        }
        bool mark = false;
        int l = 0, r = 1;
        while(r < nums.size()){
            if(nums[r] < nums[l]){
                if(mark){
                    return false;
                }
                int x = 0;
                if(l-1 < 0){
                    x = nums[r];
                }else{
                    x = nums[l-1];
                }
                if(nums[r] == x){
                    nums[l] = nums[r];
                    mark = true;
                }else{
                    nums[r] = nums[l];
                    mark = true;
                }
            }
            r++;
            l++;
        }
        return true;
    }
};

int main(){
    vector<int> test1 = {4,2,1};
    vector<int> test2 = {4,2,3};
    vector<int> test3 = {3,4,2,3};
    vector<int> test4 = {3,4,3,3};
    Solution s;
    cout<<s.checkPossibility(test1)<<endl;
    cout<<s.checkPossibility(test2)<<endl;
    cout<<s.checkPossibility(test3)<<endl;
    cout<<s.checkPossibility(test4)<<endl;




    return 0;
}