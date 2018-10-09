#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0){
            return 0;
        }
        if(sz == 1){
            return 1;
        }
        vector<int> l(sz,0);
        l[0] = 1;
        
        for(int i=1;i<sz;i++){
            int tmp = 0;
            for(int j=0;j<=i-1;j++){
                if(nums[j] < nums[i] && l[j] > tmp){
                    tmp = l[j];
                }
            }
            l[i] = tmp+1;
        }
        int tmp = 0;
        for(auto &x : l){
            if(x > tmp){
                tmp = x;
            }
        }
        return tmp;
    }
};

int main(){
    return 0;
}