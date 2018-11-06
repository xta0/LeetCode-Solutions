#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        wndsz = size;
    }
    
    double next(int val) {
        Q.push(val);
        int sz = 0;
        if(Q.size() <= wndsz){
            sum += val;
            return sum/Q.size();
            
        }else{
            int front = Q.front();
            Q.pop();
            sum -= front;
            sum += val;
            return sum / wndsz;
        }
    }
private:
    int wndsz = 0;
    queue<int> Q;
    double sum = 0.0;
};


int main(){
    MovingAverage mv(3);
    cout.precision(5);
    cout<<mv.next(1)<<endl;
    cout<<mv.next(10)<<endl;
    cout<<mv.next(3)<<endl;
    cout<<mv.next(5)<<endl;
    



    return 0;
}