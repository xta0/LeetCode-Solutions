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
Solution: Tree + Postorder Traversal
Time: O(nlogn) + O(n)
Space: O(n)
*/
/*
1. 建N-ary树, children用deque存储，便于删除第一个child
2. 对每个节点的children进行排序
3. 从JFK开始后序遍历每个节点，收集结果
4. 将结果reverse
*/
class Solution {

    void postOrderVisist(string root, unordered_map<string, deque<string>>& um, vector<string>& result){
        
        auto& children = um[root];
        //post order traversal
        while(!children.empty()){
            //smallest child
            string child = children.front();
            children.pop_front();
            postOrderVisist(child,um,result);
        }
        result.push_back(root);
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {

        //1.建树
        unordered_map<string, deque<string>> um;
        for(auto &p:tickets){
            um[p.first].push_back(p.second);
        }
        //2. 排序, worst case : O(nlog(n))
        for(auto& p: um){
            auto& children = p.second;
            sort(children.begin(),children.end());
        }
        //3. post order traversal start from JFK
        vector<string> res;
        //O(n)
        postOrderVisist("JFK",um,res);

        //4. reverse the post order sequence
        return {res.rbegin(),res.rend()};
    }
};

int main(){




    return 0;
}