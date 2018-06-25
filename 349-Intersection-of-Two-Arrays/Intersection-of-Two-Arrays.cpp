#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0){
            return {};
        }
        set<int> sets;
        set<int> ret;
        for(auto x1: nums1){
            sets.insert(x1);
        }
        for(auto x2:nums2){
            if(sets.find(x2) != sets.end()){
                ret.insert(x2);
            }
        }
        return {ret.begin(), ret.end()};
    }
};

int main(){




    return 0;
}