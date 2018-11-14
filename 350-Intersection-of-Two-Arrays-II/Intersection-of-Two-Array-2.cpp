#include <iostream>
#include <vector>
#include <string>
using namespace std;

//follow up : two arrays are sorted
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int l1 = 0;
        int l2 = 0;
        //使用双指针
        while(l1<nums1.size() && l2<nums2.size()){
            if(nums1[l1] < nums2[l2]){
                l1++;
            }
            else if(nums2[l2] < nums1[l1]){
                l2++;
            }else{
                //when nums2[l2] == nums1[l1]
                ans.push_back(nums1[l1]);
                l1++;
                l2++;
            }
        }
        return ans;
        
    }
};
int main(){




    return 0;
}