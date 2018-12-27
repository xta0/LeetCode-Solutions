#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Solution: Partial Bubble Sort
Time: O(N*k)
Space: O(1)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<k;i++){
            for(int j = nums.size()-1; j>i;j--){
                //move the larger element to the front
                if(nums[j] > nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        return nums[k-1];
    }
};

int main(){
    return 0;
}