#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;


 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto func = [](const Interval& i1, const Interval& i2){
            return i1.start < i2.start;
        };    
        
        std::sort(intervals.begin(),intervals.end(),func);
        
        for(int i=0; i<intervals.size();i++){
            Interval& il = intervals[i];
            if(i+1<intervals.size()){
                Interval& ir = intervals[i+1];
                if(il.end > ir.start){
                    return false;
                }
            }
        }
        return true;
        
    }
};
int main(){




    return 0;
}