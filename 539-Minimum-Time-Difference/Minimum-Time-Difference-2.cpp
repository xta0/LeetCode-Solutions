#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 Solution: Sort
 Time: O(Nlog(N))
 Space: O(N^2)
 */
class Solution {
public:
    int diff(int t1, int t2){
        int diff = abs(t1-t2);
        if(diff > 12*60){
            diff =  min(t1,t2) + 60*24 - max(t1,t2);
        }
        return diff;
    }
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        vector<int> times;
        for(int i=0;i<timePoints.size();i++){
            int t = stoi(timePoints[i].substr(0,2))*60 + stoi(timePoints[i].substr(3,2));
            times.push_back(t);
        }
        std::sort(times.begin(), times.end());
        //排序后，两两做差，求最小值
        //注意：时间差是环形的，最后一个元素和第一个元素之间的差值也要考虑
        for(int i=1;i<times.size();i++){
            res = min(res,diff(times[i],times[i-1]));
        }
        //计算最后一个元素和第一个元素的差值
        res = min(res, diff(times[times.size()-1],times[0]));
        
        return res;
    }
};
int main(){
    
    Solution s;
    vector<string> times = {"00:00","11:00","23:30"};
    cout<<s.findMinDifference(times)<<endl;
    
    
    return 0;
}
