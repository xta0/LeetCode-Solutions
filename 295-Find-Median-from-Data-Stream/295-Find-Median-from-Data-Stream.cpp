#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 || num<maxHeap.top()) {
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        if(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }else{
            if( (maxHeap.size() - minHeap.size()) >= 2){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return (double)maxHeap.top();
        }else{
            double t1 = (double)maxHeap.top();
            double t2 = (double)minHeap.top();
            return (t1+t2)/2;
        }
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};


/**
 ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
 [[],[1],[2],[],[3],[]]
 */

int main(){

    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout<<mf.findMedian()<<endl;
    mf.addNum(3);
    cout<<mf.findMedian()<<endl;
    
    return 0;
}
