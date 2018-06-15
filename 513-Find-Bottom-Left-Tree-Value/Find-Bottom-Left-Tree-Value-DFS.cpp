#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//模板同#112， DFS+回溯
class Solution {
    void dfs(TreeNode* root, int& level, int& depth, int& n){
        if(!root){
            return ;
        }
            level ++;
            dfs(root->left, level, depth, n );
            dfs(root->right, level, depth, n );
            
            //check the leaf
            if(!root->left && !root->right){
                if(level > depth){
                    depth = level;
                    n = root->val;
                }
            }
            //backtracking
            level--;
        
        
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int level = 0, depth = 0, n = 0;
        dfs(root,level,depth,n);
        return n;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    cout<<s.findBottomLeftValue(root)<<endl;
    
    
    
    return 0;
}
