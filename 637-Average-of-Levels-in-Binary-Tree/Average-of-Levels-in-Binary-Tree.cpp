#include <iostream>
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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root){
            return {};
        }
        if(!root->left && !root->right){
            return {(double)root->val};
        }
        vector<double> results;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            double sum = 0;
            size_t n = q.size();
            for (int i = 0; i < n; ++i){
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            results.push_back(sum/n);
        }
        return results;
    }
};

int main(){




    return 0;
}