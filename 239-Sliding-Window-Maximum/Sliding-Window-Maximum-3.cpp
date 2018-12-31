#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

/*
Solution: Balanced BST
Time: O(Nlogk)
Space: O(k)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> ms(nums.begin(),nums.begin()+k);
        ans.push_back(*ms.rbegin());

        for(int i = k; i<nums.size();i++){
            ms.insert(nums[i]);
            ms.erase(ms.find(nums[i-k]));
            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};

int main(){

    vector<int> test1 = {1,3,-1,-3,5,3,6,7};
    int k1 = 3;
    // vector<int> test2 = {-4,2,-5,3,6};
    // int k2 = 3;
    // vector<int> test3 = {9,10,9,-7,-4,-8,2,-6};
    // int k3 = 5;

    Solution s;
    auto result = s.maxSlidingWindow(test1,k1);
    for(auto x:result){
        cout<<x<<endl;
    }



    return 0;
}