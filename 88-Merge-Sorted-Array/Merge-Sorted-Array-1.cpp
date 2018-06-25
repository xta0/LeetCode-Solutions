#include <iostream>
#include <vector>
#include <string>
using namespace std;

//O(nlogn)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i =m;i<nums1.size()-1; i++){
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};

int main(){




    return 0;
}