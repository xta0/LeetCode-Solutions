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
Solution: Quick Select
Time: O(N)
Space: O(N)
*/
class Solution {
    int partition(vector<int>& nums, int lo, int hi){
        int i = lo;
        int j = hi+1;
        int p = nums[lo];
        while(true){
            do { i++; } while( i<= hi && nums[i] < p );
            do { j--; } while( nums[j] > p);
            if( i > j){
                break;
            }
            swap(nums[i],nums[j]);
        }
        swap(nums[lo],nums[j]);
        return j;
    }
    int quickSelect(vector<int>& nums, int lo, int hi, int k){
        if(lo>=hi){
            return nums[lo];
        }
        int p = partition(nums,lo,hi);
        int index = nums.size() - p;
        if(index == k){
            return nums[p];
        }else if(index > k ){
            return quickSelect(nums,p+1,hi,k);
        }else {
            return quickSelect(nums,lo,p-1,k);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0,nums.size()-1,k);
    }
};

int main(){




    return 0;
}