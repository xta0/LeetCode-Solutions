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
 更新左右边界
 Example:
 1,2,0,1,3
 1: um[1] = 1
 2: l=um[1]=1, r=0 -> um[2] = 1+1 = 2 -> um[1] = 2 | 12
 0: l=0, r=um[1]=2 -> um[0] = 2+1 = 3 -> um[1] = 3 | 123
 2: duplicated, skip
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> um;
        for(auto& n : nums){
            if(um.count(n)){
                continue;
            }
            auto itor_l = um.find(n-1);
            auto itor_r = um.find(n+1);
            int l = itor_l != um.end()?itor_l->second:0;
            int r = itor_r != um.end()?itor_r->second:0;
            if(r==0 && l==0){
                um[n] = 1;
            }else if(r >0 && l>0){
                um[n] = um[n-l] = um[n+r]= r+l+1;
            }else if(r > 0){
                um[n] = um[n+r] = r+1;
            }else{
                um[n] = um[n-l] = l+1;
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
    
    Solution s;
    vector<int> arr = {1,2,0,1,3};
    cout<<s.longestConsecutive(arr)<<endl;
    
    
    return 0;
}
