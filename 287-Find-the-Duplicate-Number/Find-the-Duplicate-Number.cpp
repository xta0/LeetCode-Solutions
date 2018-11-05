#include <iostream>
#include <vector>
#include <string>
using namespace std;

//成环法
//https://segmentfault.com/a/1190000003817671
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        //detect cycle
        do{
            //move slow 1 step
            slow = nums[slow];
            //move fast 2 steps
            fast = nums[nums[fast]];
        }while(slow != fast);
        //meet point of fast and slow
        int head = 0;
        //detect cycle point
        while(head != slow){
            slow = nums[slow];
            head = nums[head];
        }
        return head;
    }
};


int main(){




    return 0;
}