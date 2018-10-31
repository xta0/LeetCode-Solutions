#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    int maxSum = INT_MIN;
public:
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        //左子树非负节点，如果l<0则对求和没有作用
        int l = max(dfs(root->left),0);
        //右子树非负节点，同理
        int r = max(dfs(root->right),0);
        
        //更新maxSum
        maxSum = max(maxSum,l+r+root->val);
        
        //返回root+左分支或root+右分支的最大值
        return root->val + max(l,r);
 
    }
    int maxPathSum(TreeNode* root) {
        return max(dfs(root), maxSum);
    }
};



int main(){
    
    Solution s;
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(1);
//    root->right = new TreeNode(1);
//    root->left->left = new TreeNode(2);
//    root->left->right = new TreeNode(1);
//    root->right->left = new TreeNode(10);
//    root->right->right = new TreeNode(1);
    TreeNode* root = new TreeNode(-2);
    root->left = new TreeNode(1);
    cout<<s.maxPathSum(root)<<endl;
    
    
    return 0;
}
