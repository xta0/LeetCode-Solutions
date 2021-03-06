#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
 //重点是排序
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0){
            return intervals;
        }
        vector<Interval> results;
        
        //step1: sort
        sort(intervals.begin(),intervals.end(),[](Interval& it1, Interval& it2){
            return it1.start < it2.start;
        });

        //step2: merge
        int left = intervals[0].start;
        int right = intervals[0].end;
        for(auto it : intervals){
            if(it.start <= right){
                right = max(right, it.end);
            }else{
                results.push_back({left,right});
                left = it.start;
                right =it.end;
            }
        }
        results.push_back({left,right});
        return results;
    }
};

int main(){




    return 0;
}