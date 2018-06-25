#include <iostream>
#include <vector>
#include <string>
using namespace std;

//O(n), 尾部归并merge
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1=m-1, l2 = n-1; 
        int i = m+n-1; //index started from tail
        //merge
        while(l1 >=0 && l2 >= 0){
            if(nums2[l2] > nums1[l1]){
                nums1[i] = nums2[l2];
                l2--;
            }else{
                nums1[i] = nums1[l1];
                l1--;
            }
            i--;
        }
        if(l1<0){
            //put the rest of nums2 before i
            while(l2 >=0 ){
                nums1[i] = nums2[l2];
                l2--;
                i--;
            }  
        }
        if(l2<0){
            //put the rest of nums1 after i
            while(l1 >= 0){
                nums1[i] = nums1[l1];
                l1--;
                i--;
            }
        }
    }
};

int main(){




    return 0;
}