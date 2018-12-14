#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 Solution: Brute Force
 Time: O(N)
 Space: O(N^2)
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        vector<int> times;
        for(int i=0;i<timePoints.size();i++){
            int t = stoi(timePoints[i].substr(0,2))*60 + stoi(timePoints[i].substr(3,2));
            times.push_back(t);
        }
        for(int i=0;i<times.size();i++){
            for(int j=i+1;j<times.size();j++){
                int t1 = times[i];
                int t2 = times[j];
                //两两时间做差，差值最大不能超过12小时
                //如果大于12小时，用小的+24*60 - 大的
                int diff = abs(t1-t2);
                if(diff > 12*60){
                    diff = min(t1,t2)+24*60 - max(t1,t2);
                }
                res = min(res,diff);
            }
        }
        return res;
    }
};
int main(){
    
    Solution s;
    vector<string> times = {"00:00","11:00","23:30"};
    cout<<s.findMinDifference(times)<<endl;
    
    
    return 0;
}
