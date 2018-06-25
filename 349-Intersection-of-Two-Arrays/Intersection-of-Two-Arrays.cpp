#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0){
            return {};
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());        
        int l1 = 0, l2 = 0;
        while(l1<nums1.size() && l2<nums2.size()){
            //skip same elements
            while(nums1[l1] == nums2[l1+1]){
                l1++;
            }
            while(nums2[l2] == )

        }
    }
};

int main(){




    return 0;
}