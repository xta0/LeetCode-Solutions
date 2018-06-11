#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void dfs(TreeNode* root, int& depth, int& max_depth){
        if(!root){
            return;
        }
        if(root->left){
            depth ++;
            max_depth = max(max_depth,depth);
            dfs(root->left, depth,max_depth);
            depth --;
        }
        if(root->right){
            depth ++;
            max_depth = max(max_depth,depth);
            dfs(root->right,depth,max_depth);
            depth--;
        }
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int depth = 1;
        int max_depth = 1;
        dfs(root,depth,max_depth);
        return max_depth;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    cout<<s.maxDepth(root)<<endl;
    return 0;
}
