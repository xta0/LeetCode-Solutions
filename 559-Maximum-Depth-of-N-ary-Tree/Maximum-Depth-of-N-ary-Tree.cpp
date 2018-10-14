#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//BFS
//解法同104
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }
        if(root->children.empty()){
            return 1;
        }
        int depth = 0;
        std::queue<Node* > q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                Node* node = q.front();
                q.pop();
                for(auto n : node->children){
                    q.push(n);
                }
            }
            depth ++;
        }
        return depth;
        
    }
};


int main(){




    return 0;
}