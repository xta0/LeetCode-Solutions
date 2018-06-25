#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         if(nums1.size() == 0 || nums2.size() == 0){
            return {};
        }
        unordered_map<int,int> m1;
        vector<int> ret;
        for(auto x1: nums1){
            m1[x1] = m1[x1]+1 ;
        }
        for(auto x2:nums2){
            if(m1.find(x2) != m1.end()){
                if(m1[x2] != 0){
                    ret.push_back(x2);
                    m1[x2] = m1[x2] -1;
                }
            }
        }
        return ret;
    }
};
int main(){




    return 0;
}