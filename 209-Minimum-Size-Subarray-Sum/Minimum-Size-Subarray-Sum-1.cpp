#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//Brutal Force O(n^2)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                if(sum >= s){
                    flag = true;
                    len = min(len, j-i+1);
                }
            }
        }
        return flag?len:0;
    }
};

int main(){




    return 0;
}