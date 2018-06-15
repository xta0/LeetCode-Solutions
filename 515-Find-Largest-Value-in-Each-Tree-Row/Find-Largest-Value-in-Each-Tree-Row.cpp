#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//BFS
class Solution
{
  public:
    vector<int> largestValues(TreeNode *root){
        if(!root){
            return {};
        }
        if(!root->left && !root->right){
            return {root->val};
        }
        vector<int> results;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int min_v = INT_MIN;
            size_t n = q.size();
            for (int i = 0; i < n; ++i){
                TreeNode *node = q.front();
                q.pop();
                min_v = max(min_v, node->val);
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            results.push_back(min_v);
        }
        return results;
    }
};

int main(){
    return 0;
}