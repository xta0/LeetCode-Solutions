#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()){
            return false;
        }
        set<int> sets;
        for(auto x: nums){
            if(sets.find(x) != sets.end()){
                return true;
            }
            sets.insert(x);
        }
        return false;
    
    }
};
int main(){




    return 0;
}