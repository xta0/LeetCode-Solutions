#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
Solution: Deque
Time: O(N)
Space: O(k)
*/
class Solution {
public:
    void adjustDeque(deque<int>& dq, int x){
        while(!dq.empty() && x > dq.back()){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()){
            return {};
        }
        vector<int> result;
        deque<int> dq;
        //initialize deque 
        for(int i=0;i<k;i++){
            int x = nums[i];
            adjustDeque(dq,x);
        }
        result.push_back(dq.front());
        //window move:
        for(int i=0;i<nums.size()-k;i++){
            //leave window
            int x = nums[i];
            if(x == dq.front()){
                dq.pop_front();
            }
            //enter window
            int y = nums[i+k];
            adjustDeque(dq,y);
            result.push_back(dq.front());
        }
        
        return result;
    }
};


int main(){

    vector<int> test1 = {1,3,-1,-3,5,3,6,7};
    int k1 = 3;
    vector<int> test2 = {-4,2,-5,3,6};
    int k2 = 3;
    vector<int> test3 = {9,10,9,-7,-4,-8,2,-6};
    int k3 = 5;

    Solution s;
    auto result = s.maxSlidingWindow(test3,k3);
    for(auto x:result){
        cout<<x<<endl;
    }


    return 0;
}