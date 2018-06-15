#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//BFS
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root->left && !root->right){
            return root->val;
        }
        int n = INT_MIN;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            size_t sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                 q.push(node->right);
                }
            }
            if(q.size() > 0){
                n = q.front()->val;
            }
        }
        return n;
    }
};

int main(){




    return 0;
}