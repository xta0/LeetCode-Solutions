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
public:
    void dfs(TreeNode* root,int depth,int& maxd){
        if(!root){
            return;
        }
        maxd = max(maxd,depth);
        dfs(root->left,depth+1,maxd);
        dfs(root->right,depth+1,maxd);
        
    }
    int maxDepth(TreeNode* root) {
        int maxd = 0;
        dfs(root,1,maxd);
        return maxd;
        
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
