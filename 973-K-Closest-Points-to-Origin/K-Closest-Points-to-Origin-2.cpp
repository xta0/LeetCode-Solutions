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


/*
 Solution: Sort
 Time: O(NlogN)
 Space: O(1)
 */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),[&](const vector<int>& p1, const vector<int>& p2){
           int d1 = p1[0]*p1[0] + p1[1]*p1[1];
           int d2 = p2[0]*p2[0] + p2[1]*p2[1];
           return d1<d2; 
        });
        return {points.begin(),points.begin()+K};
    }
};
int main(){




    return 0;
}