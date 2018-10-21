#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int> pq;
    int kth;
public:
    KthLargest(int k, vector<int> nums) {
        kth = k;
        pq = priority_queue<int>(nums.begin(),nums.end());
    }
    
    int add(int val) {
        pq.push(val);
        for(int i=0;i<kth;i++){
            pq.pop();
        }
        return pq.top();
    }
};

int main(){
    KthLargest o(3,{4,5,8,2});
    cout<<o.add(3)<<endl;
    cout<<o.add(5)<<endl;
    cout<<o.add(10)<<endl;
    cout<<o.add(9)<<endl;
    cout<<o.add(4)<<endl;



    return 0;
}