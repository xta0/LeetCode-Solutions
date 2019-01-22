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
 Solution: Max Heap
 Time: O(Nlog(K))
 Space: O(K)
 */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<int> maxHeap;
        unordered_multimap<int,vector<int>> um;
        for(auto& pt : points){
            int d = pt[0]*pt[0] + pt[1]*pt[1];
            if(maxHeap.size() < K){
                um.insert({d,pt});
                maxHeap.push(d);
            }else{
                
                int dt = maxHeap.top();
                if(d < dt){
                    maxHeap.pop();
                    auto itor = um.find(dt);
                    um.erase(itor);
                    
                    maxHeap.push(d);
                    um.insert({d,pt});
                }
            }
        }
        vector<vector<int>> res;
        for(auto& p:um){
            res.push_back(p.second);
        }
        
        return res;
    }
};

int main(){
    
    vector<vector<int>> input = {
        {-5,4},
        {-6,-5},
        {4,6}
    };
    Solution s;
    auto result = s.kClosest(input, 2);
    for(auto p:result){
        cout<<"{"<<p[0]<<","<<p[1]<<"}";
    }
    cout<<endl;
    
    
    return 0;
}
