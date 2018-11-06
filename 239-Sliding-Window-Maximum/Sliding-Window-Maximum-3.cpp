#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

//使用bst
//multiset
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> ms;
        //create window
        for(int i=0;i<k;i++){
            ms.insert(nums[i]);
        }
        ans.push_back(*(--ms.end()));
        
        for(int i=1;i<nums.size()-k;i++){
            //删除注意使用迭代器
            ms.erase(ms.find(nums[i-1]));
            ms.insert(nums[i+k-1]);
            ans.push_back(*(--ms.end()));
        }
        return ans;
    }
};

int main(){

    // vector<int> test1 = {1,3,-1,-3,5,3,6,7};
    // int k1 = 3;
    // vector<int> test2 = {-4,2,-5,3,6};
    // int k2 = 3;
    vector<int> test3 = {9,10,9,-7,-4,-8,2,-6};
    int k3 = 5;

    Solution s;
    auto result = s.maxSlidingWindow(test3,k3);
    for(auto x:result){
        cout<<x<<endl;
    }



    return 0;
}