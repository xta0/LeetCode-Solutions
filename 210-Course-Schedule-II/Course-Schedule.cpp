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
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        //edge cases
        if(!numCourses){
            return {};
        }
        //we need two DS, graph & in-degrees
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int,int> degrees;
        
        //1. create graph & initialize in-degree array
        for(auto& p : prerequisites){
            //初始化每个点的入度为0
            if(!degrees.count(p.second)){
                degrees[p.second] = 0;
            }
            graph[p.second].insert(p.first);
            degrees[p.first] += 1;
        }
        
        //create a queue for BFS
        queue<int> q;
        
        //2. 入度为0的节点先入队
        for(auto& d:degrees){
            if(d.second == 0){
                q.push(d.first);
            }
        }
        vector<int> res;
        //3. 入度为0的出队
        while(!q.empty()){
            int id = q.front();
            res.push_back(id);
            q.pop();
            auto children = graph[id];
            for(auto c : children){
                degrees[c] -=1;
                if(degrees[c] == 0){
                    q.push(c);
                }
            }
        }
        
        //4. 检查拓扑结构是否有环
        for(auto& p:degrees){
            if(p.second != 0){
                return {};
            }
        }
        
        //5. 对于没有依赖的课程，放到数组后面
        for(int i=0;i<numCourses;i++){
            if(!degrees.count(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};


int main(){
    
    Solution s;
    
//    vector<pair<int,int>> p = {{1,0},{2,0},{3,1},{3,2}};
//    auto v =  s.findOrder(4,p);
    
//    vector<pair<int,int>> p = {{1,0}};
//    auto v =  s.findOrder(3,p);
    
    vector<pair<int,int>> p = {};
    auto v =  s.findOrder(1,p);
    
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
}
