#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> _minHeap;
    int _k;
    
public:
    KthLargest(int k, vector<int> nums) {
        _k = k;
        for(int i=0;i<nums.size();i++){
            _minHeap.push(nums[i]);
            if(_minHeap.size() > k){
                _minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        _minHeap.push(val);
        if(_minHeap.size() > _k){
            _minHeap.pop();
        }
        return _minHeap.top();
    }
};

int main(){
    KthLargest o(2,{0});
//    KthLargest o(1,{});
    cout<<o.add(-1)<<endl;
    cout<<o.add(1)<<endl;
    cout<<o.add(-2)<<endl;
    cout<<o.add(-4)<<endl;
    cout<<o.add(3)<<endl;
//    priority_queue<int> pq;

    
    
    
    return 0;
}
