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

//拓扑排序
//BFS
//图 ——> 入度为0 -->BFS
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0 ){
            return "";
        }
        //构建图
        unordered_map<string, unordered_set<string>> graph;
        //保存出·度为0的节点
        vector<int> degrees;
        
        
    }
    void constructGraph(vector<string>& words, unordered_map<string,unordered_set<string>>& graph){
        for(int i=0;i<words.size();i++){
            
        }
    }
};
int main(){




    return 0;
}