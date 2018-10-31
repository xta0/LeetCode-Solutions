#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        map<int,vector<int>> cache;
        queue<pair<int,TreeNode* >> q;
        q.push({0,root});
        while(!q.empty()){
            pair<int,TreeNode* >& p = q.front();
            q.pop();
            int index = p.first;
            TreeNode* node=  p.second;
            cache[index].push_back(node->val);
            if(node->left){
                q.push({index-1,node->left});
            }
            if(node->right){
                q.push({index+1,node->right});
            }
        }
        vector<vector<int>> ans;
        for(auto &p:cache){
            ans.push_back(p.second);
        }
        return ans;
    }
};

int main(){




    return 0;
}