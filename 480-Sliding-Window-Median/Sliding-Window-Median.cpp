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

//使用两个heap。思路同295
class Solution {
    priority_queue<int> maxHeap;
    priority_queue<int,std::vector<int>,greater<int>> minHeap;
    
    void addNumberToHeap(int n){
        if(maxHeap.empty() || n<maxHeap.top()){
            maxHeap.push(n);
        }else{
            minHeap.push(n);
        }
        if()
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        
        
    }
};

int main(){




    return 0;
}