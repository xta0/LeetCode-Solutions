#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()){
            return {};
        }

        vector<int> ret;
        map<int,int> m;
        //O(n)
        for(auto x:nums){
            m[x] = m[x] + 1;
        }
        //O(n)
        auto comp = [](const pair<int,int>&p1,const pair<int,int>&p2){ return p1.second < p2.second; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq{m.begin(),m.end(),comp};
        
        //O(n)
        for(int i=0;i<k;i++){
            int n = pq.top().first;
            pq.pop();
            ret.push_back(n);
        }
        return ret;
    }
};

int main(){




    return 0;
}