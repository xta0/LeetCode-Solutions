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
public:
    //计算树的深度模板
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        return 1+max(depth(root->left), depth(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){return 0;}
        if(!root->left && !root->right){ return 0; }
        //case1: 最长路径中包含根节点，则取 depth(left) + depth(right) +1
        //case2: 最长路径中不包含根节点，则取max(depth(left),depth(right))
        //递归操作
        int left = depth(root->left);
        int right = depth(root->right);
        int ret =  max(left+right, max(left,right));
        return ret;

    }
};

int main(){




    return 0;
}