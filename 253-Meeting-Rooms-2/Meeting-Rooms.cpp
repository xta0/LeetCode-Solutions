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

    int minMeetingRooms(vector<Interval>& intervals) {
        auto func = [](const Interval& i1, const Interval& i2){
            return i1.start < i2.start;
        }; 
        auto hasInterval = [](const Interval& i1, const Interval& i2){
            return i1.end>i2.start;
        };

        int count = 1;
        Interval curr = intervals[0];
        int i = 1;
        while(i<intervals.size()){
            if(hasInterval(curr,intervals[i])){
                count++;
            }
            curr = intervals[i];
            i++;
        }
        return count;
    }
};

int main(){




    return 0;
}