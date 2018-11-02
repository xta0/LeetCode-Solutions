#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
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
        
    }
};

int main(){




    return 0;
}