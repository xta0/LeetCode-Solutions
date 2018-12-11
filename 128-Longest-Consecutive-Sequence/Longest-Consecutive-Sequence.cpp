#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Solution: Hashmap
Time: O(N)
Space: O(N)

Hashmap<int,int>: key is num, value is len

Example:
100, 4, 200, 1, 3, 2
{100:1}
{4:1}
{200:2} -> 1+1 = 2 -> 100,200
{1:1}
{3:2} -> 1+1 = 2 -> 3,4
{2:4} -> 1+2+1 = 4 -> 1,2,3,4
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> um;
        for(auto& n : nums){
            int r = 0;
            int l = 0;
            //check hashmap
            if(um.count(n-1)){
                l = nums[n-1];
            }
            if(um.count(n+1)){
                r = nums[n+1];
            }
            if(r==0 && l==0){
                nums[n] = 1;
            }else if(r >0 && l>0){
                nums[n] = r+l+1;
            }else if(r > 0 &&  l==0){
                nums[n] = r+1;
            }else{
                nums[n] = l+1;
            }
        }
        int maxl = 0;
        for(auto& p : um){
            maxl = max(maxl,p.second);
        }
        return maxl;
    }
};
int main(){




    return 0;
}