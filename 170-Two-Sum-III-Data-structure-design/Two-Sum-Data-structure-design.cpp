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

class TwoSum {
    //key: num, value:count
    unordered_map<int,int> us;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        us[number] ++ ;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto &p:us){
            int x = p.first;
            int target = value - x;
            if(us.count(target) && ( x!=target || p.second > 1) ){
                return true;
            }
        }
        return false;
    }
};

int main(){




    return 0;
}