#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq = {nums.begin(), nums.end()};
        for(int i=0;i<k;i++){
            pq.pop();
        }
        return pq.top();;
    }
};

int main(){

    return 0;
}