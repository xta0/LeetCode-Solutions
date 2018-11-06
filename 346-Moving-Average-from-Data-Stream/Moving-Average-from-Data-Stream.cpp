#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//O(n) solution
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        wndsz = size;
    }
    
    double next(int val) {
        data.push_back(val);
        size_t lbound = 0;
        size_t sz = 0;
        if(data.size() > wndsz){
            lbound = data.size() - wndsz;
            sz = wndsz;
        }else{
            lbound = 0;
            sz = data.size();
        }
        double sum  = 0;
        for(size_t i =lbound; i<data.size(); i++){
            sum+= data[i];
        }
        double result = sum/sz;
        return result;
    }
private:
    int wndsz = 0;
    vector<int> data;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int main(){
    
    MovingAverage mv(3);
    cout.precision(5);
    cout<<mv.next(1)<<endl;
    cout<<mv.next(10)<<endl;
    cout<<mv.next(3)<<endl;
    cout<<mv.next(5)<<endl;
    
    
    return 0;
}
