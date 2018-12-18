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
 
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
 /*
 Solution: Hashmap
 Time: O(N)
 Space: O(N)
 */
 //参考：https://www.educative.io/collection/page/5642554087309312/5679846214598656/50003
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        //<key:origNode, value:clonedNode>
        unordered_map<UndirectedGraphNode* ,UndirectedGraphNode* > um;
        return dfs(node,um);
    }
    UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode* ,UndirectedGraphNode* >um){
        if(!node){
            return nullptr;
        }
        if(um.count(node)){
            return um[node];
        }
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        um[node] = root;
        for(auto orig : node->neighbors){
            //递归
            root->neighbors.push_back(dfs(orig,um));
        }
        return root;
    }
};
int main(){




    return 0;
}