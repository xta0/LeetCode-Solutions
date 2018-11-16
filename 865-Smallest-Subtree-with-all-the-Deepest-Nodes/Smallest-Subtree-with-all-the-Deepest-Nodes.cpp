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

class Solution {
    //calculate the max depth of any node
    void depth(TreeNode* root, int d, int& maxd){
        if(!root){
            return;
        }
        maxd = max(maxd,d);
        depth(root->left,d+1,maxd);
        depth(root->right,d+1,maxd);
        
    }
    void dfs(TreeNode* root, TreeNode*& ans){
        
        //calculate the depth of left and right substree
        int l=0; int r =0;
        depth(root->left,1,l);
        depth(root->right,1,r);
        
        //if l==r, means root is the answer
        if(l == r){
            ans = root;
        }else if(l > r){
            //depth of left subtree is greater than right
            dfs(root->left,ans);
        }else{
            //depth of right subtree is greater than left
            dfs(root->right,ans);
        }
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans = root;
        dfs(root,ans);
        return ans;
    }
};
    
int main(){




    return 0;
}