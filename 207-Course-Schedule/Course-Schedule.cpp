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
Solution: TopoSort + BFS
Time: O(N)
Space: O(N)
*/
class Solution {

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int,int> degrees;
        for(auto& p : prerequisites){
            //初始化每个点的入度为0
            if(!degrees.count(p.first)){
                degrees[p.first] = 0;
            }
            graph[p.first].insert(p.second);
            degrees[p.second] += 1;
        }
        
        queue<int> q;
        
        //1. 入度为0的节点先入队
        for(auto& d:degrees){
            if(d.second == 0){
                q.push(d.first);
            }
        }
        
        if(q.empty()){
            return false;
        }
        
        //出队入度为0的
        while(!q.empty()){
            int id = q.front();
            q.pop();
            auto children = graph[id];
            for(auto c : children){
                degrees[c] -=1;
                if(degrees[c] == 0){
                    q.push(c);
                }
            }
        }
        
        //3. 判断是否要有入度不为0的点，
        for(auto& p:degrees){
            if(p.second != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    
    Solution s;
    vector<pair<int,int>> p = {{1,0},{0,1}};
    bool b = s.canFinish(2,p);
    cout<<b<<endl;
    
    
    
    
    return 0;
}
