#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        size_t sz1 = nums1.size();
        size_t sz2 = nums2.size();
        vector<int> temp;
        int i= 0, j=0;
        while(i<sz1 && j<sz2){
            int s1 = nums1[i];
            int s2 = nums2[j];
            if(s1<=s2){
                temp.push_back(s1);
                i++;
            }else{
                temp.push_back(s2);
                j++;
            }
        }
        if(i==sz1){
            auto itor = nums2.begin();
            itor+=j;
            temp.insert(temp.end(), itor,nums2.end());
        }
        if(j==sz2){
            auto itor = nums1.begin();
            itor+=i;
            temp.insert(temp.end(), itor,nums1.end());
        }
        if(temp.size() % 2 == 1){
            return (double)temp[temp.size()/2];
        }else{
            double l1 = (double)temp[temp.size()/2-1];
            double l2 = (double)temp[temp.size()/2];
            return (l1+l2)/2;
        }
    }
};

int main(){
    return 0;
}
