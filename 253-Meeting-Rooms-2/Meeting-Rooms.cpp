#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <functional>

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

        if(intervals.size() == 0){
            return 0;
        }
        auto func = [](const Interval& i1, const Interval& i2){
            return i1.start < i2.start;
        }; 
        std::sort(intervals.begin(),intervals.end(),func);
        
        //create a min heap
        // priority_queue<Interval,std::vector<Interval>,function<bool(const Interval&, const Interval&)>> pq( [](const Interval& i1, const Interval& i2 ){
            // return i1.end > i2.end;
        // });
        priority_queue<int,std::vector<int>,std::greater<int>> pq;
        pq.push(intervals[0].end);
        // pq.push(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            Interval itv = intervals[i];
            int itop = pq.top();
            if(itv.start < itop){
                pq.push(itv.end);
            }else{
                //merge two
                pq.pop();
                pq.push(itv.end);
            }
        }
        return pq.size();
    }
};

int main(){




    return 0;
}